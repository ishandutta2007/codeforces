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

int n, m, a[200][200], x, q, r, c;
pair<int, int> qq[200][200];
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("a.in", "r",  stdin));
    cin >> n >> m >> q;
    forn (i, n)
        forn (j, m) qq[i][j] = {i, j};
    forn (i, q) {
        int p;
        cin >> p >> r;
        r--;
        if (p == 1) {
            pair<int, int> a = qq[r][0];
            for (int i = 0; i + 1 < m; i++)
                    qq[r][i] = qq[r][i + 1];
            qq[r][m - 1] = a;
            continue;
        }
        if (p == 2) {
            pair<int, int> a = qq[0][r];
            for (int i = 0; i + 1 < n; i++)
                qq[i][r] = qq[i + 1][r];
            qq[n - 1][r] = a;
            continue;
        }
        cin >> c >> x;
        c--;
        a[qq[r][c].fi][qq[r][c].se] = x;
    }
    forn (i, n) {
        forn (j, m) cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}