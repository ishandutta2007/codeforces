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

    string s, t;
    cin >> s >> t;

    for(int i = 0; i < s.size(); i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;

    for(int i = 0; i < t.size(); i++)
        if(t[i] >= 'A' && t[i] <= 'Z')
            t[i] += 32;

    if(s < t)
        cout << -1;
    else if(s == t)
        cout << 0;
    else cout << 1;
}