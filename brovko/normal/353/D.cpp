#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    vector <int> dp(n + 1);

    int km = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'M')
        {
            km++;
            dp[i + 1] = dp[i];
        }
        else if(km)
            dp[i + 1] = max(dp[i] + 1, km);
    }

    cout << dp[n];
}