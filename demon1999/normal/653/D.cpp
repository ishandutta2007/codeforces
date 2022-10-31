#include <bits/stdc++.h>
#define forn(i, n) for(ll i = 0; i < int(n); i++)
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
typedef double ld;
using namespace std;

struct T { int x, y; };
T t = {1, 2};
const int ma = 2 * 131072;

ll n, m, a, b, x, f[100][100], c[100][100], f1[100][100], fr[100], use[100];
vector<ll> edge[ma], we1[ma], we2[ma];
double ans;

ll dfs(int nu, int pr, ll k) {
    fr[nu] = pr;
    if (nu == n - 1) {
        re k;
    }
    for (int i = 0; i < n; i++) {
        if (fr[i] == -2 && c[nu][i] - f1[nu][i] > 0) {
            int p = dfs(i, nu, min(k, c[nu][i] - f1[nu][i]));
            if (p > 0) re p;
        }
    }
    re -1;
}

bool ok(double m) {
   //cout << m << endl;
    forn(i, n) {
        forn(j, n) {
            c[i][j] = ll(ld(f[i][j]) / m + 1e-9);
            //cout << c[i][j] << " ";
            f1[i][j] = 0;
        }
        //cout << endl;
    }
    ll flow = 0;
    for (;;) {
        forn (i, n) fr[i] = -2;
        ll cc = dfs(0, -1, 100000000000000LL);
        //cout << cc << endl;
        if (cc <= 0) break;
        int nu = n - 1;
        while (nu != 0) {
                //cout << nu << " " << fr[nu] << " ";
            f1[fr[nu]][nu] += cc;
            f1[nu][fr[nu]] -= cc;
            nu = fr[nu];
        }
        //cout << endl;
        /*forn (i, n) {
            forn (j, n)
                cout << c[i][j] - f1[i][j] << " ";
            cout << endl;
        }*/
    }
    forn (i, n)
        if (c[0][i])
            flow += f1[0][i];
    //cout << flow << " " << x << endl;
    if (flow >= x) re true;
    re false;
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qqq.in", "r",  stdin));
    cin >> n >> m >> x;
    forn (i, m) {
        ll w;
        cin >> a >> b >> w;
        a--;
        b--;
        f[a][b] += w;
    }
    double l = 0, r = 100000000;
    //ok(0.35);
    //re 0;
    forn(i, 100) {
        //cout << l << " " << r << endl;
        double mid = (l + r) / 2;
        if (ok(mid)) l = mid;
        else r = mid;
    }
    cout.precision(35);
    cout << l * ld(x);
    return 0;
}