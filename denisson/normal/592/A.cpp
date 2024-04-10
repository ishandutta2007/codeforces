#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
#define forn(i, n) for (ll i = 0; i < (ll)n; i++)
#define fornm(i, n, m) for (ll i = n; i <= (ll)m; i++)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define TASK "a"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 1;
const ll LINF = (ll)9e18 + 7;

char a[10][10];
int ans1 = INF, ans2 = INF;

str con(int a)
{
    str s1 = "";
    while (a > 0)
    {
        s1 += '0' + a % 10;
        a /= 10;
    }
    reverse(s1.begin(), s1.end());
    return s1;
}

int main()
{
    //freopen("input.in", "r", stdin); //freopen("output.txt", "w", stdout);
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            cin >> a[i][j];
    for (int j = 1; j <= 8; j++)
    {
        int n1 = -INF, n2 = INF;
        bool f = true;
        for (int i = 1; i <= 8; i++)
        {
            if (a[i][j] == 'B')
            {
                n1 = max(n1, i);
                f = false;
            }
            if (a[i][j] == 'W')
            {
                if (f)
                    n2 = min(n2, i);
                else
                {
                    n1 = -INF;
                }

            }
        }
        if (n1 != -INF && n2 == INF)
            ans2 = min(ans2, 8 - n1);
        if (n1 == -INF && n2 != INF)
            ans1 = min(ans1, n2 - 1);
        if (n1 != -INF && n2 != INF)
        {
            if (n1 > n2)
            {
                ans1 = min(ans1, n2 - 1);
                ans2 = min(ans2, 8 - n1);
            }
        }
    }
    //cout << ans1 << ' ' << ans2;
    if (ans1 <= ans2)
        cout << 'A';
    else
        cout << 'B';
}