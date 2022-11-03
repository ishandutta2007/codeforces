#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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

const int MAXN = 1000000;

int n, a[308], b[308];
vec < pair <int, int> > ans;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    //freopen("INPUT.in", "r", stdin);
    cin >> n;
    forn(i, n)
        cin >> b[i];
    forn(i, n)
        cin >> a[i];
    forn(i, n)
    {
        int q = b[i], q1;
        for (int j = i; j < n; j++)
            if (a[j] == q)
            {
                q1 = j;
                break;
            }
        for(int j = q1 - 1; j >= i; j--)
            /*cout << j + 1 << ' ' << j + 1 + 1 << LN,*/ ans.pb(mp(j + 1, j + 2)), swap(a[j], a[j + 1]);

    }
    cout << ans.size() << LN;
    forn(i, ans.size())
        cout << ans[i].XX << ' ' << ans[i].YY << LN;
}
//190660JM