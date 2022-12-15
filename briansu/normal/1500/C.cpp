#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector A(n, vector(m, 0));
    vector B(n, vector(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> B[i][j];

    vector inv_cnt(m, 0), u(n, 0);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] > B[i + 1][j])
                inv_cnt[j]++;

    queue<int> q;
    vector<int> ord;
    for (int j = 0; j < m; j++)
        if (inv_cnt[j] == 0)
            q.push(j);

    while (SZ(q)) {
        int t = q.front(); q.pop();
        ord.pb(t);
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n - 1 && B[j][t] == B[j + 1][t])
                j++;
            // [i, j]
            if (j < n - 1 && !u[j]) {
                for (int k = 0; k < m; k++)
                    if (B[j][k] > B[j + 1][k]) {
                        --inv_cnt[k];
                        if (inv_cnt[k] == 0)
                            q.push(k);
                    }
                u[j] = 1;
            }
            i = j + 1; 
        }
    }
    reverse(ALL(ord));

    // cerr << SZ(ord) << endl;
    // for (auto t : ord)
    //     cerr << t << " ";
    // cerr << endl;

    for (ll t : ord)
        stable_sort(ALL(A), [&](auto &L, auto &R) { return L[t] < R[t]; });
    if (A != B)
        cout << -1 << endl;
    else {
        cout << SZ(ord) << "\n";
        for (int i = 0; i < SZ(ord); i++)
            cout << ord[i] + 1 << " \n"[i == SZ(ord) - 1];
    }
}