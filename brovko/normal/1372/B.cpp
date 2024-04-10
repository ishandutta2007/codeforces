#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int f = 0;
        
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0 && f == 0)
            {
                cout << n / i << ' ' << n - n / i << "\n";
                f = 1;
            }
        }
        
        if(f == 0)
            cout << 1 << ' ' << n - 1 << "\n";
    }
}