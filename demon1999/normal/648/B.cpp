#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
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
using namespace std;

const ll mod = 998244353;
int n, m, xmi = mod, xma = -mod;
string s;
vector<int> a;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("bridge.in", "r",  stdin);
    //freopen("bridge.out", "w", stdout);
    cin >> n;
    vector<pair<int, int> > a;
    a.resize(2 * n);
    forn (i, 2 * n) {
        cin >> a[i].fi;
        a[i].se = 0;
    }
    sort(a.begin(), a.end());
    forn (i, n) {
        cout << a[i].fi << " " << a[2 * n - i - 1].fi << "\n";
    }
    return 0;
}