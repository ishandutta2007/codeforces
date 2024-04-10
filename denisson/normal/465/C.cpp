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

int n, p;
str s;

int main()
{
    //freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);
    if (is_testing)
    {
    }
    cin >> n >> p >> s;
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        for (char c = s[i] + 1; c <= 'a' + p - 1; c++)
        {
            bool f = true;
            if (i - 1 >= 0)
            {
                if (s[i - 1] == c)
                    f = false;
            }
            if (i - 2 >= 0)
            {
                if (s[i - 2] == c)
                    f = false;
            }
            if (f)
            {
                str kek = s;
                kek[i] = c;
                for (int j = i + 1; j < s.size(); j++)
                {
                    for (char c1 = 'a'; c1 <= 'a' + p - 1; c1++)
                    {
                        bool f1 = true;
                        if (j - 1 >= 0)
                        {
                            if (kek[j - 1] == c1)
                                f1 = false;
                        }
                        if (j - 2 >= 0)
                        {
                            if (kek[j - 2] == c1)
                                f1 = false;
                        }
                        if (f1)
                        {
                            kek[j] = c1;
                            break;
                        }
                    }
                }
                cout << kek << LN;
                exit(0);
            }
        }
    }
    cout << "NO";
}