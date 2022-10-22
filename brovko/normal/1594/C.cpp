#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int F[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        for(int i = 1; i <= n; i++)
            F[i] = 1;

        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j += i)
                if(s[j - 1] != c)
                    F[i] = 0;

        int f = 0;

        if(F[1])
        {
            cout << "0\n";
        }
        else
        {
            for(int i = 1; i <= n; i++)
                if(F[i] && f == 0)
                {
                    f = 1;
                    cout << "1\n" << i << "\n";
                }

            if(f == 0)
                cout << "2\n" << n - 1 << ' ' << n << "\n";
        }
    }
}