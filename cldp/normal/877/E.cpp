#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<int> x[MAXN];
int L[MAXN], R[MAXN];
vector<int> S;

int bj[MAXN], cnt[MAXN], ini[MAXN];

void dfs(int a) {
    L[a] = S.size();
    S.push_back(a);
    for (int i = 0; i < x[a].size(); ++i) dfs(x[a][i]);
    R[a] = S.size() - 1;
}

void build(int t, int l, int r) {
    if (l == r) {
        cnt[t] = ini[S[l]];
        return ;
    }
    int mid = (l + r) / 2;
    build(t + t, l, mid);
    build(t + t + 1, mid + 1, r);
    cnt[t] = cnt[t + t] + cnt[t + t + 1];
}

void clear(int t, int l, int r) {
    bj[t] = 0;
    int mid = (l + r) / 2;
    bj[t + t] = 1 - bj[t + t];
    cnt[t + t] = mid - l + 1 - cnt[t + t];
    bj[t + t + 1] = 1 - bj[t + t + 1];
    cnt[t + t + 1] = r - mid - cnt[t + t + 1];
}

void insert(int t, int a, int b, int l, int r) {
    if (l == r) {
        if (bj[t]) bj[t] = 0;
        cnt[t] = 1 - cnt[t];
        return ;
    }
    if (bj[t]) clear(t, l, r);
    if (a <= l && r <= b) {
        bj[t] = 1;
        cnt[t] = r - l + 1 - cnt[t];
        return ;
    }
    int mid = (l + r) / 2;
    if (a <= mid && l <= b) insert(t + t, a, b, l, mid);
    if (a <= r && mid + 1 <= b) insert(t + t + 1, a, b, mid + 1, r);
    cnt[t] = cnt[t + t] + cnt[t + t + 1];
}

int query(int t, int a, int b, int l, int r) {
    if (l == r) return cnt[t];
    if (bj[t]) clear(t, l, r);
    if (a <= l && r <= b) return cnt[t];
    int ans = 0;
    int mid = (l + r) / 2;
    if (a <= mid && l <= b) ans += query(t + t, a, b, l, mid);
    if (a <= r && mid + 1 <= b) ans += query(t + t + 1, a, b, mid + 1, r);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        int a;
        cin >> a;
        x[a].push_back(i);
    }
    S.push_back(0);
    dfs(1);
    for (int i = 1; i <= N; ++i) cin >> ini[i];

    build(1, 1, N);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string trash;
        int a;
        cin >> trash >> a;
        if (trash == "get") {
            cout << query(1, L[a], R[a], 1, N) << endl;
        } else {
            insert(1, L[a], R[a], 1, N);
        }
    }

    return 0;
}