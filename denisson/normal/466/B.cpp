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
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
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
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const bool is_testing = 0;
const ll MOD = 1e9 + 7;

ll n, a, b;
bool f = false;

void check (ll s)
{
    for (ll i = a; i * i <= s; i++)
        if (s % i == 0)
        {
            if (a <= i && b <= (s / i))
            {
                if (!f)
                    cout << s << LN << i << ' ' << s / i;
                else
                    cout << s << LN << s / i << ' ' << i;
                exit(0);
            }
        }
}

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
    }
    cin >> n >> a >> b;
    if (6 * n <= a * b)
        cout << a * b << LN << a << ' ' << b, exit(0);
    if (a > b)
        swap(a, b), f = true;
    for (ll s = (ll)6 * n; ; s++)
        check(s);
}