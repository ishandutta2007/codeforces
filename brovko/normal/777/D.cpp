#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];

    for(int i = n - 2; i >= 0; i--)
    {
        int j = 0;

        while(j < s[i].size() && j < s[i + 1].size() && s[i][j] == s[i + 1][j])
            j++;

        if(j < s[i + 1].size() && s[i][j] <= s[i + 1][j])
            j = s[i].size();

        s[i] = s[i].substr(0, j);
    }

    for(int i = 0; i < n; i++)
        cout << s[i] << "\n";
}