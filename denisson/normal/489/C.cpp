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
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
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

const bool is_testing = 0;
const int p = 31;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 11;
const int MAXN = 2e5 + 7;

int m, s;
vec<int> a, b;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    srand(14123);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> m >> s;
    if (s == 0 && m > 1)
        cout << "-1 -1", exit(0);
    if (m * 9 < s)
        cout << "-1 -1", exit(0);
    if (m == 1 && s == 0)
        cout << "0 0", exit(0);
    //
    int k = s;
    forn(i, m)
    {
        int q = min(9, k);
        a.pb(q);
        k -= q;
    }

    //min
    b = a;
    if (b[m - 1] == 0)
    {
        cout << 1;
        bool f = 1;
        for (int i = m - 2; i >= 0; i--)
        {
            if (f && b[i])
                b[i]--, f = 0;
            cout << b[i];
        }
    }
    else
    {
        for (int i = m - 1; i >= 0; i--)
            cout << b[i];
    }
    //
    cout << ' ';
    //max
    forn(i, a.size())
        cout << a[i];
}
//190660JM