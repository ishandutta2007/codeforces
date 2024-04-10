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

const int MAXn = 2e5 + 5;
vector<int> v[MAXn];
int a[MAXn], dg[MAXn], u[MAXn];
int n;
ll go(int start_clr) {
    for (int i = 1; i <= n; i++)
        dg[i] = SZ(v[i]), u[i] = 0;
    queue<int> q[3];
    for (int i = 1; i <= n; i++)
        if (dg[i] <= 1)
            q[a[i]].push(i), u[i] = 1;
    int ans = 0;
    int cur = start_clr;
    while (SZ(q[0]) || SZ(q[1]) || SZ(q[2])) {
        // cerr << SZ(q[0]) << " " << SZ(q[1]) << " " << SZ(q[2]) << endl;
        ++ans;
        while (SZ(q[0]) || SZ(q[cur])) {
            int t;
            if (SZ(q[0]))
                t = q[0].front(), q[0].pop();
            else
                t = q[cur].front(), q[cur].pop();
            for (int x : v[t])
                if (!u[x]) {
                    --dg[x];
                    if (dg[x] == 1)
                        u[x] = 1, q[a[x]].push(x);
                }
        }
        cur = 3 - cur;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            v[i].clear();
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1, x, y; i < n; i++)
            cin >> x >> y, v[x].pb(y), v[y].pb(x);
        cout << min(go(1), go(2)) << "\n";        
    }
}