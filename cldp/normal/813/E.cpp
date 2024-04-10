#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], y[MAXN], P[MAXN][22];
int A[MAXN];
vector<int> X[MAXN * 8];

void build(int t, int l, int r) {
    if (l == r) {
        X[t].push_back(A[l]);
        return ;
    }
    int mid = (l + r) / 2;
    build(t + t, l, mid);
    build(t + t + 1, mid + 1, r);
    X[t].reserve(r - l + 1);
    for (int i = 0; i < X[t + t].size(); ++i) X[t].push_back(X[t + t][i]);
    for (int i = 0; i < X[t + t + 1].size(); ++i) X[t].push_back(X[t + t + 1][i]);
    sort(X[t].begin(), X[t].end());
}

int query(int t, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
        return lower_bound(X[t].begin(), X[t].end(), a) - X[t].begin();
    }
    int mid = (l + r) / 2, ans = 0;
    if (a <= mid && l <= b) ans += query(t + t, l, mid, a, b);
    if (mid + 1 <= b && a <= r) ans += query(t + t + 1, mid + 1, r, a, b);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> x[i];
    for (int i = 1; i <= 100000; ++i) y[i] = 0;
    for (int i = 1; i <= N; ++i) {
        P[i][0] = y[x[i]];
        y[x[i]] = i;
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= N; ++j) P[j][i] = P[P[j][i - 1]][i - 1];
    }
    for (int i = 1; i <= N; ++i) {
        A[i] = i;
        for (int j = 0; j < 20; ++j) {
            if (K & (1 << j)) A[i] = P[A[i]][j];
        }
    }

    build(1, 1, N);
    int M;
    cin >> M;
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a = (a + ans) % N + 1;
        b = (b + ans) % N + 1;
        if (a > b) swap(a, b);
       // cout << a << " " << b << endl;
        ans = query(1, 1, N, a, b);
        cout << ans << endl;
    }

    return 0;
}