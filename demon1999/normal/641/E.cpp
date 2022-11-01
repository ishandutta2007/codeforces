#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n, m, szz[1000000];
pair<pii, int> pp[1000000];
vector<int> a[1000000];
vector<pair<pii, pii> > qq;

int sum(int i, int l, int r) {
    if (l > r) re 0;
    if (l % 2) re a[i][l] + sum(i, l + 1, r);
    if (r % 2 == 0) re a[i][r] + sum(i, l, r - 1);
    re sum(i, l / 2, r / 2);
}
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("a.in", "r",  stdin));
    cin >> n;
    qq.resize(n);
    forn (i, n) {
        cin >> qq[i].se.fi >> qq[i].fi.se >> qq[i].fi.fi;
        qq[i].se.se = i;
    }
    sort(qq.begin(), qq.end());
    int k = 0, p = 0;
    forn (i, n) {
        if (i && qq[i].fi.fi != qq[i - 1].fi.fi) {
            k++;
            p = 0;
        }
        else
            if (i && qq[i].fi.se != qq[i - 1].fi.se) p++;
        pp[qq[i].se.se] = mp(mp(k, p), qq[i].se.fi);
        szz[k] = p + 1;
    }
    forn (i, k + 1) {
        //cout << i << endl;
        int j = 1;
        while (j <= szz[i]) j *= 2;
        szz[i] = j;
        a[i].assign(2 * j, 0);
    }
    forn (i, n) {
        int nu = pp[i].fi.fi; int nu2 = pp[i].fi.se + szz[nu];
        if (pp[i].se == 1) {
            while (nu2) {
                a[nu][nu2]++;
                nu2 /= 2;
            }
            continue;
        }
        if (pp[i].se == 2) {
            while (nu2) {
                a[nu][nu2]--;
                nu2 /= 2;
            }
            continue;
        }
        //cout << nu << " " << szz[nu] << " " << nu2 << endl;
        cout << sum(nu, szz[nu], nu2) << "\n";
    }
    return 0;
}