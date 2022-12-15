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

int mnpm[1123456];
vector<int> pm;
vector<int> stk[1123456];
int a[1123456];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 2; i <= 1000000; i++) {
        if (!mnpm[i])
            pm.pb(i), mnpm[i] = i;
        for (int j = 0; pm[j] * i <= 1000000; j++) {
            mnpm[pm[j] * i] = pm[j];
            if (i % pm[j] == 0)
                break;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> g;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '*') {
            int x = a[i];
            while (x != 1)
                stk[mnpm[x]].pb(i), x /= mnpm[x];
            g.pb(i);
        }
        else {
            // /
            int cur = i, x = a[i];
            if (x == 1)
                g.pb(i);
            else {
                while (x != 1) {
                    int t = mnpm[x]; x /= mnpm[x];
                    if (!SZ(stk[t])) {
                        cur = -1;
                        break;
                    }
                    cur = min(cur, stk[t].back());
                    stk[t].pop_back();
                }
                while (SZ(g) && g.back() > cur)
                    g.pop_back();
            }
        }
        ans += SZ(g);
    }
    cout << ans << endl;
}