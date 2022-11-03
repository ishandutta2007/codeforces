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

str s1, s2;
int dp[200007][2];
ll ans = 0;

int main()
{
    cin >> s1 >> s2;
    dp[0][s2[0] - '0'] = 1;
    for (int i = 1; i < s2.size(); i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][s2[i] - '0']++;
    }
    forn(i, s1.size())
    {
        int q = (s1[i] - '0' + 1) % 2;
        if (i == 0)
            ans += dp[s2.size() - s1.size() + i][q];
        else
            ans += dp[s2.size() - s1.size() + i][q] - dp[i - 1][q];
    }
    cout << ans;
}