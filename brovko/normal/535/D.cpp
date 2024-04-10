#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a[1000005], pref[2000005];
string p, s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;

    for(int i = 0; i < n; i++)
        s += "?";

    int x = 0;

    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
        a[i]--;

        for(int j = max(x, a[i]); j < a[i] + p.size(); j++)
            s[j] = p[j - a[i]];

        x = a[i] + (int)p.size() - 1;
    }

//    cout << s << endl;

    string t = p + "#" + s;
    int k = 0;

    for(int i = 1; i < t.size(); i++)
    {
        while(k > 0 && t[k] != t[i])
            k = pref[k - 1];

        if(t[k] == t[i])
            k++;

        pref[i] = k;
    }

    for(int i = 0; i < m; i++)
        if(pref[2 * p.size() + a[i]] < p.size())
        {
            cout << 0;
            return 0;
        }

    int ans = 1;

    for(auto to:s)
        if(to == '?')
            ans = ans * 26 % 1000000007;

    cout << ans;
}