#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, Max[500005], ans[500005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    int x = 0;

    for(int i = 0; i <= n; i++)
        Max[i] = -1;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            x++;

            if(i == 0)
                ans[i] = 1;
            else ans[i] = ans[i - 1] + i - Max[x];
        }
        else
        {
            x = 0;
            int y = 0;
            int z = i - 1;

            while(z >= 0 && s[z] == '1')
            {
                y++;
                Max[y] = z;
                z--;
            }

            if(i > 0)
                ans[i] = ans[i - 1];
        }
    }

    int f = 0;

    for(int i = 0; i < n; i++)
        f += ans[i];

    cout << f;
}