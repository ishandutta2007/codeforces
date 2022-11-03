#include <bits/stdc++.h>
using namespace std;

const int kInf = 1e9;
const int kMaxN = 1e3;

int cost[kMaxN][kMaxN];
int n;
int q[kMaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cost[i][j] = kInf;
        }
    }

    int m;
    cin >> m;
    vector<pair<int, pair<int, int> > > e(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        cost[b][a] = min(cost[b][a], c);
    }

    vector<bool> used(n, false);

    int answer = 0;
    for (int itr = 0; itr + 1 < n; ++itr) {
        int mn = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && (mn == -1 || q[i] < q[mn])) {
                mn = i;
            }
        }
        used[mn] = true;
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            if (cost[mn][i] != kInf && (mx == -1 || cost[mn][i] < cost[mn][mx])) {
                mx = i;
            }
        }
        if (mx == -1) {
            cout << -1 << endl;
            return 0;
        }
        answer += cost[mn][mx];
    }

    cout << answer << endl;

    return 0;
}