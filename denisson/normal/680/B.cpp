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

int n, k;
int a[107];

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
        freopen("input.txt", "r", stdin);
        freopen("input.out", "w", stdout);
    }
    cin >> n >> k;
    k--;
    forn(i, n)
        cin >> a[i];
    int d = 0;
    int ans = 0;
    while (1)
    {
        if (k - d >= 0)
        {
            if (k + d < n)
            {
                int q = a[k + d] + a[k - d];
                if (q == 2)
                    ans += 2;
                if (q == 2 && d == 0)
                    ans--;
            }
            else
            {
                int q = a[k - d];
                if (q == 1)
                    ans++;
            }
        }
        else
        {
            if (k + d < n)
            {
                int q = a[k + d];
                if (q == 1)
                    ans++;
            }
            else
                break;
        }
        d++;
    }
    cout << ans;
}