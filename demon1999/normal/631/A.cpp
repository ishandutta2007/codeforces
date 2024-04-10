#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < ll(n); i++)
#define rep(i, n) for(int i = 0; i < ll(n); i++)
#define mp(i, j) make_pair(i, j)
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
const ll mod = 1e9 + 7;
ll n, m, a, b, ans = 0;
vector<ll> aa, bb;
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("a.out", "w", stdout);
    cin >> n;
    aa.resize(n);
    bb.resize(n);
    forn (i, n) cin >> aa[i];
    forn (i, n) cin >> bb[i];
    forn (i, n) {
        ll k = 0, c = 0;
        for (int j = i; j < n; j++) {
            k |= aa[j];
            c |= bb[j];
            ans = max(ans, k + c);
        }
    }
    cout << ans;
    return 0;
}