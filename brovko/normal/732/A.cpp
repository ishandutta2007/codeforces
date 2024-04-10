#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int k, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> r;
    
    for(int i = 1; i <= 10; i++)
    {
        if(i * k % 10 == 0 || i * k % 10 == r)
        {
            cout << i;
            return 0;
        }
    }
}