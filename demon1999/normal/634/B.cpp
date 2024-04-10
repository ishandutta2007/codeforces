
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < ll(n); i++)
#define rep(i, n) for(int i = 0; i < ll(n); i++)
//#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
//#define int long long
#define vi vector<int>
typedef long long ll;
typedef double ld;
using namespace std;
const ll pr = 239, mod = 1e9 + 7;
string s;
ll n, m, ans = 1, qq[42];

signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 41; i >= 0; i--) {
        if ((m & (1LL << i))) {
            n -= (1LL << i);
            ans *= 2;
        }
        else qq[i + 1] = 1;
    }
    for (ll i = 41; i >= 0; i--)
        if ((n & (1LL << i))) {
            if (!qq[i]) {
                cout << 0;
                re 0;
            }
        }
    if (n == 0) {
        cout << ans - 2;
        re 0;
    }
    cout << ans;
    return 0;
}