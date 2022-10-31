#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
const ll mod = 1e9 + 7, sz = 200;

ll day[1000000], n;
vector<ll> m, r;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("matrix.in", "r",  stdin));
    //freopen("matrix.out", "w", stdout);
    cin >> n;
    ll a = 1;
    m.resize(n);
    r.resize(n);
    forn (i, n) {
        cin >> m[i];
        a = (a * m[i]) / __gcd(a, m[i]);
    }
    forn(i, n) cin >> r[i];
    forn (i, n) {
        while (r[i] < a) {
            day[r[i]] = 1;
            r[i] += m[i];
        }
    }
    int k = 0;
    forn (i, a)
        k += day[i];
    cout.precision(30);
    cout << ld(k) / ld(a);
    return 0;
}