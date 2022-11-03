#include <bits/stdc++.h>
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
#define clr(a, n) memset(a, n, sizeof(a));
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
const int MAXN = 1e5 + 8;

int n, k;
vec< pair<int, int> > a;
vec<int> ans;


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> k;
    a.resize(n);
    forn(i, n)
        cin >> a[i].XX, a[i].YY = i;
    sort(all(a));
    forn(i, a.size())
        if (k - a[i].XX >= 0)
        {
            k -= a[i].XX;
            ans.pb(a[i].YY);
        }
        else
            break;
    cout << ans.size() << LN;
    forn(i, ans.size())
        cout << ans[i] + 1 << ' ';

}
//190660JM