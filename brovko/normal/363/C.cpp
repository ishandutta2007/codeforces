#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    string t;

    for(int i = 0; i < s.size(); i++)
    {
        if(t.size() < 2 || !(t[t.size() - 1] == t[t.size() - 2] && t[t.size() - 1] == s[i]))
            t += s[i];
    }

    string ans;

    for(int i = 0; i < t.size(); i++)
    {
        if(ans.size() < 3 || !(ans[ans.size() - 2] == ans[ans.size() - 3] && ans[ans.size() - 1] == t[i]))
            ans += t[i];
    }

    cout << ans;
}