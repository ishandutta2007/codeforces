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
ll n, m, a;
pair<int, int> ism[5000], ism1[5000];
vector<int> aa[5000];
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("a.out", "w", stdout);
    cin >> n >> m >> a;
    //forn (i, n) aa[i].assign(a, 0);
    forn (i, a) {
        int k, r, c;
        cin >> k >> r >> c;
        r--;
        if (k == 1) {
            ism[r] = mp(c, i + 1);
        }
        else ism1[r] = mp(c, i + 1);
    }
    forn (i, n) {
        forn (j, m) {
            //cout << ism[i].fi << " " << ism1[i].fi << endl;
            if (ism[i] == mp(0, 0)) {
                cout << ism1[j].fi;
            }
            else
            if (ism1[j] == mp(0, 0)) {
                cout << ism[i].fi;
            }
            else
                if (ism[i].se < ism1[j].se) cout << ism1[j].fi;
            else cout << ism[i].fi;
            cout << " ";
            //cout << endl;
        }
        cout << endl;
    }
    return 0;
}