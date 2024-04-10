#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x[600005], t[600005];
string s[600005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> s[i];
        if(s[i] == "add")
            {
                cin >> x[i];
                t[x[i]] = i;
            }
    }

    vector <int> v;
    int T = -1;
    int y = 1;
    int ans = 0;

    for(int i = 0; i < 2 * n; i++)
    {
        if(s[i] == "add")
            v.push_back(x[i]);
        else
        {
            if(v[v.size() - 1] == y || t[v[v.size() - 1]] <= T)
                v.pop_back();
            else
            {
                T = i;
                ans++;
            }

            y++;
        }
    }

    cout << ans;
}