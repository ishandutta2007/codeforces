
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
const ll ma = 1024 * 256;
string s;
ll n, m, a, b, k, q, treea[2 * ma], treeb[2 * ma];

ll suma(int l, int r) {
    if (l > r) re 0;
    if (l % 2) re treea[l] + suma(l + 1, r);
    if (r % 2 == 0) re treea[r] + suma(l, r - 1);
    re suma(l / 2, r / 2);
}

ll sumb(int l, int r) {
    if (l > r) re 0;
    if (l % 2) re treeb[l] + sumb(l + 1, r);
    if (r % 2 == 0) re treeb[r] + sumb(l, r - 1);
    re sumb(l / 2, r / 2);
}

signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("a.out", "w", stdout);
    cin >> n >> k >> a >> b >> q;
    int pp, day, al, nu;
    forn (i, q) {
        cin >> pp;
        if (pp == 1) {
            cin >> day >> al;
            day--;
            nu = day + ma;
            treea[nu] += al;
            treeb[nu] += al;
            if (treea[nu] > a) treea[nu] = a;
            if (treeb[nu] > b) treeb[nu] = b;
            while ((nu / 2)) {
                nu /= 2;
                treea[nu] = treea[2 * nu] + treea[2 * nu + 1];
                treeb[nu] = treeb[2 * nu] + treeb[2 * nu + 1];
            }
            continue;
        }
        cin >> day;
        day--;
        cout << sumb(ma, ma + day - 1) + suma(ma + day + k, 2 * ma - 1) << "\n";
    }
    return 0;
}