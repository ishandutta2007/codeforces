#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;

        if(n % 2)
        {
            if(n == 1)
                cout << "FastestFinger\n";
            else cout << "Ashishgup\n";
        }
        else
        {
            int F = 0;

            while(n % 2 == 0)
                {
                    n /= 2;
                    F++;
                }

            int f = 0;

            for(int i = 3; i * i <= n; i++)
                if(n % i == 0)
                    f = 1;

            if(F == 1)
            {
                if(f == 1 || n == 1)
                    cout << "Ashishgup\n";
                else cout << "FastestFinger\n";
            }
            else
            {
                if(n == 1)
                    cout << "FastestFinger\n";
                else cout << "Ashishgup\n";
            }
        }
    }
}