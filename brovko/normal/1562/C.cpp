#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n;
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

        int F = 0;

        for(int i = 0; i < n / 2; i++)
            if(s[i] == '0' && F == 0)
            {
                F = 1;

                cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << "\n";
            }

        for(int i = n / 2; i < n; i++)
            if(s[i] == '0' && F == 0)
            {
                F = 1;

                cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << "\n";
            }
            
        if(F == 0)
            cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << "\n";
    }
}