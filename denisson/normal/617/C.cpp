#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//

#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)

//
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const bool is_testing = false;
const int MAXN = 1e6 + 7;


ll n, x1, x2, y1, y2;
vec<ll> a, b;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> x1 >> y1 >> x2 >> y2;
    forn(i, n)
    {
        ll z1, z2;
        cin >> z1 >> z2;
        ll k1 = (x1 - z1) * (x1 - z1) + (y1 - z2) * (y1 - z2);
        ll k2 = (x2 - z1) * (x2 - z1) + (y2 - z2) * (y2 - z2);
        a.pb(k1);
        b.pb(k2);
    }
    //forn(i, n)
    //    cout << a[i] << ' ' << b[i] << LN;
    ll ans = LINF;
    forn(i, n + 1)
    {
        ll q = a[i], q1 = 0;
        if (i == n)
            q = 0;
        forn(i, n)
            if (a[i] > q)
            {
                q1 = max(q1, b[i]);
            }
        ans = min(q1 + q, ans);
    }
    cout << ans;
}
//190660JM