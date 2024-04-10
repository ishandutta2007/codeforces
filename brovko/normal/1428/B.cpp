#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, ans[300005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        for(int i = 0; i < n; i++)
            ans[i] = 0;

        int k1 = 0, k2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '>')
                k1++;

            if(s[i] == '<')
                k2++;
        }

        if(k1 == 0 || k2 == 0)
            cout << n << "\n";
        else
        {
            for(int i = 0; i < n; i++)
                if(s[i] == '-')
                {
                    ans[i] = 1;
                    ans[(i + 1) % n] = 1;
                }

            int k = 0;

            for(int i = 0; i < n; i++)
                k += ans[i];

            cout << k << "\n";
        }
    }
}