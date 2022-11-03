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
const int MAXN = 1e5 + 7;

int n, m;
vec < pair <int, int> > a;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> m;
    a.rs(n);
    forn(i, n)
        cin >> a[i].XX >> a[i].YY;
    sort(all(a));
    //forn(i, n)
    //    cout << a[i].XX << ' ' << a[i].YY << LN;
    ll ans = 0;
    int uk1 = n - 1;
    forn(i, n)
    {
        if (a[i].XX - a[0].XX >= m)
        {
            uk1 = i - 1;
            break;
        }
        else
            ans += (ll)a[i].YY;
    }
    int uk = 0;
    ll ans2 = ans;
    for (int i = uk1 + 1; i < n; i++)
    {
        ll ans1 = ans2;
        ans1 += (ll)a[i].YY;
        while(a[i].XX - a[uk].XX >= m)
        {
            uk++;
            ans1 -= (ll)a[uk - 1].YY;
            //cout << "======" << i + 1 << LN;
        }
        //cout << ans1 << ' ' << uk + 1 << ' ' << i + 1 << LN;
        ans = max(ans, ans1);
        ans2 = ans1;
    }
    cout << ans;
}
//190660JM