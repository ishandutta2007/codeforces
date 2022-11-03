#include <bits/stdc++.h>
#define XX first
#define YY second
#define db long double
#define str string
#define ll long long
#define vec vector
#define re return
#define sz size
#define in insert
#define y1 x345t89nm0238c50345df34nm5d3245d83dj83j980df96345d35d34d
#define pb push_back
#define mp make_pair
#define LN '\n'
#define sp(a) fixed << setprecision(a)
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)

using namespace std;
const int INF = 2e9 + 7;
const db pi = acos(-1.0);

int n, dp[507][507];
vec <int> a;

void gen()
{
    forn(i, n)
        for (int l = 0, r = i; r < n; r++, l++)
        {
            if (l == r)
                dp[l][r] = 1;
            else
            {
                dp[l][r] = 1 + dp[l + 1][r];
                if (a[l] == a[l + 1])
                    dp[l][r] = min(dp[l][r], 1+ dp[l + 2][r]);
                for(int k = l + 2; k <= r; k++)
                if (a[l] == a[k])
                    dp[l][r] = min(dp[l][r], dp[l + 1][k - 1] + dp[k + 1][r]);
            }
        }
}

int main()
{
    cin >> n;
    forn(i, n)
    {
        int z;
        cin >> z;
        a.pb(z);
    }
    gen();
    cout << dp[0][n - 1];
}