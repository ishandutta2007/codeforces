#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int k;

int f(int x)
{
    int s=0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    int x=1;
    while(true)
    {
        if(f(x)==10)
        {
            k--;
            if(k==0)
            {
                cout << x;
                return 0;
            }
        }
        x++;
    }
}