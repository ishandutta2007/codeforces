#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, used[200005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;

        vector <int> v[26];
        int n = s.size();

        for(int i = 0; i < n; i++)
            v[s[i] - 'a'].push_back(i);

        for(int i = 0; i < n; i++)
            used[i] = 0;

        for(int i = 0; i < 26; i++)
        {
            if(v[i].size() > 0)
                used[v[i][v[i].size() - 1]] = 1;
        }

        for(int i = 0; i < 26; i++)
        {
            int x = -1, y = 0;

            while(y < n && used[y] != 1)
            {
                if(used[y] == 0)
                    x = max(x, (int)s[y] - 'a');

                y++;
            }

            if(y == n)
                break;

            x = max(x, (int)s[y] - 'a');

            int z = 0;

            while(used[z] == -1 || s[z] - 'a' != x)
            {
                used[z] = -1;
                z++;
            }

            cout << s[z];

            for(int j = 0; j < n; j++)
                if(s[j] == s[z])
                    used[j] = -1;
        }

        cout << "\n";
    }
}