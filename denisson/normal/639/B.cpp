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

int n, d, h;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("segments.dat", "r", stdin); freopen("segments.sol", "w", stdout);
    srand(14123);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> d >> h;
    int N = n;
    n--;
    if (2 * h < d)
        cout << -1, exit(0);
    int k = 1;
    if (d == 1)
    {
        if (n > 1)
        {
            cout << -1;
            exit(0);
        }
    }
    forn(i, h)
        cout << k << ' ' << k + 1 << LN, n--, k++;
    if (h == d)
    {
        int z = k - 1;
        while(n > 0)
        {
            k++;
            n--;
            cout << z << ' ' << k << LN;
        }
    }
    else
    {
        while(n > 0)
        {
            k++;
            cout << 1 << ' ' << k << LN;
            n--;
            if (k == N)
                exit(0);
            forn(i, d - h - 1)
            {
                cout << k << ' ' << k + 1 << LN;
                k++;
                n--;
                if (k == N)
                    exit(0);
            }
        }
    }


}
//190660JM