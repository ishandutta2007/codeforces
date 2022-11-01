
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
ll n, m;
vector<ll> a, p, b;
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("a.out", "w", stdout);
    cin >> n;
    b.resize(n - 1);
    forn (i, n - 1) {
        cin >> b[i];
        if (b[i] == 0) i--;
    }
    a.resize(n);
    p.resize(n + 1);
    p[0] = 1;
    forn (i, n) p[i + 1] = (p[i] * pr) % mod;
    ll hs = 0;
    forn (i, n - 1) {
        hs = (hs * pr + b[i]) % mod;
    }
    b.resize(n - 1);
    forn (i, n - 1) {
        cin >> b[i];
        if (b[i] == 0) i--;
    }
    n--;
    a.assign(n + 1, 0);
    forn (i, n) {
        //cout << b[i] << " " << endl;
        a[i + 1] = (a[i] * pr + b[i]) % mod;
    }

    for (int i = 0; i < n; i++) {
        //cout << (((((a[n] - p[n - i] * a[i])%mod) * p[i]) % mod + a[i]) % mod + mod) % mod << endl;
        if (hs == (((((a[n] - p[n - i] * a[i])%mod) * p[i]) % mod + a[i]) % mod + mod) % mod) {
            cout << "YES";
            re 0;
        }
    }
    cout << "NO";
    return 0;
}