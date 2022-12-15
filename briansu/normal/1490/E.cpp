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

int d[MAXn], dt[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> d[i], dt[i] = d[i];
        sort(dt + 1, dt + 1 + n);
        ll pre = 0, mx = 0;
        for (int i = 1; i <= n; i++) {
            if (pre < dt[i])
                mx = dt[i];
            pre += dt[i];
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            if (d[i] >= mx)
                ans.pb(i);
        cout << SZ(ans) << endl;
        for (int i = 0; i < SZ(ans); i++)
            cout << ans[i] << " \n"[i == SZ(ans) - 1];
    }
    
}