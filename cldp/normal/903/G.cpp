#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int MAXM = 1000010;
const long long INFF = 1LL * 1000000000 * 1000000000;
const double PI = acos(-1.0);

struct seg {
    long long x[MAXM], mi[MAXM];

    seg() {
        memset(x, 0, sizeof(x));
        memset(mi, 0, sizeof(mi));
    }

    void clear(int t) {
        x[t + t] += x[t];
        x[t + t + 1] += x[t];
        mi[t + t] += x[t];
        mi[t + t + 1] += x[t];
        x[t] = 0;
    }

    void insert(int t, int a, int b, int l, int r, long long add) {
        if (a <= l && r <= b) {
            x[t] += add;
            mi[t] += add;
            return ;
        }
        clear(t);
        int mid = (l + r) / 2;
        if (a <= mid && l <= b) insert(t + t, a, b, l, mid, add);
        if (a <= r && mid + 1 <= b) insert(t + t + 1, a, b, mid + 1, r, add);
        mi[t] = min(mi[t + t], mi[t + t + 1]);
    }

    long long query(int t, int a, int b, int l, int r) {
        if (a <= l && r <= b) return mi[t];
        clear(t);
        int mid = (l + r) / 2;
        long long ans = INFF;
        if (a <= mid && l <= b) ans = min(ans, query(t + t, a, b, l, mid));
        if (a <= r && mid + 1 <= b) ans = min(ans, query(t + t + 1, a, b, mid + 1, r));
        return ans;
    }
};

int x[MAXN], y[MAXN];
vector<pair<int, int> > X[MAXN];
seg A, B;

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i < N; ++i) {
        cin >> x[i] >> y[i];
        B.insert(1, i + 1, i + 1, 1, N + 1, y[i]);
    }
 //   for (int i = 1; i <= N + 1; ++i) cout << i << " " << B.query(1, i, i, 1, N + 1) << endl;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        X[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < X[i].size(); ++j) B.insert(1, 1, X[i][j].first, 1, N + 1, X[i][j].second);
        long long temp = B.query(1, 1, N, 1, N + 1);
        A.insert(1, i, i, 1, N, x[i] + temp);
    }
    
  //  cout << endl;
  //  for (int i = 1; i <= N; ++i) cout << i << " " << A.query(1, i, i, 1, N) << endl;


    cout << A.query(1, 1, N, 1, N) << endl;
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        A.insert(1, a, a, 1, N, b - x[a]);
        x[a] = b;
        cout << A.query(1, 1, N, 1, N) << endl;
    }
    return 0;
}