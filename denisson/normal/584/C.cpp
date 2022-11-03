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
const int MOD = 1e9 + 7;

int n, k, q;
str s1, s2;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    //freopen("INPUT.in", "r", stdin);
    cin >> n >> k >> s1 >> s2;
    k = n - k;
    q = 0;
    forn(i, n)
        if (s1[i] == s2[i])
            q++;
    if (q >= k)
    {
        forn(i, n)
            if (s1[i] != s2[i])
            {
                for (int c = 'a'; c <= 'z'; c++)
                {
                    if (c != s1[i] && c != s2[i])
                    {
                        cout << (char)c;
                        break;
                    }
                }
            }
            else
            {
                if (k > 0)
                {
                    k--;
                    cout << s1[i];
                }
                else
                {
                    for (int c = 'a'; c <= 'z'; c++)
                    {
                        if (c != s1[i] && c != s2[i])
                        {
                            cout << (char)c;
                            break;
                        }
                    }

                }
            }
    }
    else
    {
        k = k - q;
        if (k * 2 <= n - q)
        {
            int k1 = k;
            int k2 = k;
            forn(i, n)
                if (s1[i] == s2[i])
                    cout << s1[i];
                else
                {
                    if (k1 > 0)
                    {
                        k1--;
                        cout << s1[i];
                    }
                    else
                    {
                        if (k2 > 0)
                        {
                            k2--;
                            cout << s2[i];
                        }
                        else
                        {
                            for (int c = 'a'; c <= 'z'; c++)
                            {
                                if (c != s1[i] && c != s2[i])
                                {
                                    cout << (char)c;
                                    break;
                                }
                            }
                        }
                    }
                }
        }
        else
        {
            cout << -1;
        }
    }
}
//190660JM