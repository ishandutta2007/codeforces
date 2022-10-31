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
int n, m, a, b;
vector<pair<ll, char> > aa, bb;
vector<ll> qq, pi, pos;
char ch;
deque<pair<int, int> > kk;

bool ok(int nu1, int nu2) {
    re (aa[nu1].se == bb[nu2].se && aa[nu1].fi >= bb[nu2].fi);
}
signed main(){
    //iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &m);
    forn (i, n) {
        scanf("%d-%c", &a, &ch);
        if (!aa.empty() && aa[sz(aa) - 1].se == ch) {
            aa[sz(aa) - 1].fi += ll(a);
        }
        else aa.push_back(mp(a, ch));
    }
    forn (i, m) {
        scanf("%d-%c", &a, &ch);
        if (!bb.empty() && bb[sz(bb) - 1].se == ch) {
            bb[sz(bb) - 1].fi += ll(a);
        }
        else bb.push_back(mp(a, ch));
        //cout << a << " " << ch << endl;
    }
    ll k = 0;
    if (sz(bb) == 1) {
        for (int i = 0; i < sz(aa); i++) {
            if (aa[i].se == bb[0].se) k += max(0LL, aa[i].fi - bb[0].fi + 1);
        }
        cout << k;
        re 0;
    }
    if (sz(bb) <= 2) {
        for (int i = 0; i + sz(bb) - 1 < sz(aa); i++) {
            bool ok = true;
            for (int j = 0; j < sz(bb); j++) {
                if (aa[i + j].se == bb[j].se && aa[i + j].fi >= bb[j].fi) continue;
                ok = false;
            }
            if (ok) k++;
        }
        cout << k;
        re 0;
    }
    for (int i = 1; i + 1 < sz(bb); i++) {
        qq.push_back(bb[i].fi);
        qq.push_back(-int(bb[i].se));
        pos.push_back(0);
        pos.push_back(0);
    }
    qq.push_back(-int('#'));
    pos.push_back(0);
    for (int i = 1; i + 1 < sz(aa); i++) {
        qq.push_back(aa[i].fi);
        qq.push_back(-int(aa[i].se));
        pos.push_back(i);
        pos.push_back(i);
    }
    pi.assign(sz(qq), 0);
    //cout << qq[0] << " " << pi[0] << endl;;
    for (int i = 1; i < sz(qq); i++) {
        //cout << pos[i] << endl;
        int j = pi[i - 1];
        while (j && qq[j] != qq[i]) j = pi[j - 1];
        if (qq[j] == qq[i]) j++;
        pi[i] = j;
        //cout << pi[i] << endl;
        if (pi[i] == 2 * sz(bb) - 4) {
            //cout << "HEH " << pos[i] + 1 << " " << pos[i] - sz(bb) + 2 << endl;
            if (ok(pos[i] + 1, sz(bb) - 1) && ok(pos[i] - sz(bb) + 2, 0))k++;
        }
    }
    cout << k;
    return 0;
}