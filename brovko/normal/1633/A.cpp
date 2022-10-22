#include <bits/stdc++.h>
//#define int long long
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

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        if(n % 7 == 0)
        {
            cout << n << "\n";
            continue;
        }

        int x = 0;

        for(int i = 0; i < 10; i++)
            if((n / 10 * 10 + i) % 7 == 0)
                x = i;

        cout << n / 10 * 10 + x << "\n";
    }
}