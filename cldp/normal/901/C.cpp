#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 300010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<pair<int, int> > X, Y;
int xx[MAXN];
vector<int> x[MAXN];
int dfn[MAXN], low[MAXN];
stack<int> S;

// point biconnected
// edge biconnected is just removing bridges
// one single edge or one vertex is a biconnected component
int block(int a, int f, int &time) {
    dfn[a] = low[a] = time; 
    S.push(a);
    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i] == f) continue;
        if (dfn[x[a][i]] == 0) {
            block(x[a][i], a, ++time);
            low[a] = min(low[a], low[x[a][i]]);
            if (low[x[a][i]] >= dfn[a]) {
                int L = INF, R = -1, cnt = 0;
                while (S.top() != x[a][i]) {
                    L = min(L, S.top());
                    R = max(R, S.top());
                    ++cnt;
                    S.pop();
                }
                if (cnt == 0) {
                    S.pop();
                    continue;
                }
                L = min(L, S.top());
                R = max(R, S.top());
                L = min(L, a);
                R = max(R, a);
                X.push_back(make_pair(L, R));
                S.pop();
            }
        } else {
            low[a] = min(low[a], dfn[x[a][i]]);
        }
    }
    return 0;
}

LL cnt[MAXN], sum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    int times = 1;
    for (int i = 1; i <= N; ++i) {
        if (dfn[i] == 0) block(i, -1, times);
    }
    if (X.size() > 0) {
        sort(X.begin(), X.end());
        int L = X[0].first, R = X[0].second;
        for (int i = 1; i < X.size(); ++i) {
            if (X[i].second > R) {
                Y.push_back(make_pair(L, R));
                xx[L] = R;
            }
            L = X[i].first;
            R = X[i].second;
        }
        Y.push_back(make_pair(L, R));
        xx[L] = R;
    }

    int R = N + 1;
    for (int i = N; i >= 1; --i) {
        if (xx[i] != 0) R = min(R, xx[i]);
        cnt[i] = R - i;
    }

    for (int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + cnt[i];

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        int L = a, R = b;

        if (a == b) {
            cout << 1 << endl;
            continue;
        }
        long long ans = 0;
        if (cnt[a] > b - a + 1) {
            ans = 1LL * (b - a + 2) * (b - a + 1) / 2;
            cout << ans << endl;
            continue;
        }
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            if (cnt[mid] > b - mid + 1) R = mid; else L = mid;
        }
        ans = sum[L] - sum[a - 1];
        ans += 1LL * (b - R + 2) * (b - R + 1) / 2;
        cout << ans << endl;
    }

    return 0;
}