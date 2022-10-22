#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int ans = 0;
    char c = 'a';

    for(int i = 0; i < s.size(); i++)
    {
        ans += min((s[i] - c + 26) % 26, (c - s[i] + 26) % 26);
        c = s[i];
    }

    cout << ans;
}