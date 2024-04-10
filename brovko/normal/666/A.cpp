#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

string s;
int dp[100005][2];
map <string, int> m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    for(int i = n - 2; i >= 5; i--)
    {
        if(i == n - 2)
            dp[i][0] = 1;

        if(dp[i + 2][1] == 1)
            dp[i][0] = 1;

        if(dp[i + 2][0] == 1 && (s[i + 2] != s[i] || s[i + 3] != s[i + 1]))
            dp[i][0] = 1;

        if(i == n - 3)
            dp[i][1] = 1;

        if(dp[i + 3][0] == 1)
            dp[i][1] = 1;

        if(dp[i + 3][1] == 1 && (s[i + 3] != s[i] || s[i + 4] != s[i + 1] || s[i + 5] != s[i + 2]))
            dp[i][1] = 1;

        if(dp[i][0])
            m[s.substr(i, 2)]++;

        if(dp[i][1])
            m[s.substr(i, 3)]++;
    }

    vector <string> v;

    for(auto to:m)
        v.push_back(to.first);

    cout << v.size() << "\n";

    for(auto to:v)
        cout << to << "\n";
}