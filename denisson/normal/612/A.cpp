#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
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
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}


int n, k1, k2;
pair <int, int> ans = mp(-1, -1);
str s;

int main()
{
    //freopen("output.in", "r", stdin); //freopen("speeding.out", "w", stdout);
    //freopen("approximate.in", "r", stdin); freopen("approximate.out", "w", stdout);
    cin >> n >> k1 >> k2;
    cin >> s;
    forn(i, 100)
        forn(j, 100)
            if (i*k1 + j*k2 == n)
            {
                ans = mp(i, j);
                break;
            }
    if (ans == mp(-1, -1))
        cout << -1;
    else
    {
        cout << ans.XX + ans.YY << LN;
        int k = 0;
        while (ans.XX > 0)
        {
            int q1 = k1;
            while (q1 > 0)
            {
                cout << s[k];
                k++; q1--;
            }
            cout << LN;
            ans.XX--;
        }
        while (ans.YY > 0)
        {
            int q1 = k2;
            while (q1 > 0)
            {
                cout << s[k];
                k++; q1--;
            }
            cout << LN;
            ans.YY--;
        }
    }
}