#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, x;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> x;
        int f=0;

        if(x==0)
        {
            cout << "1 1" << endl;
            f=1;
        }

        if(x%4==2)
        {
            cout << -1 << endl;
            f=1;
        }

        for(int i=1; i*i<x; i++)
            if(x % i==0)
        {
            int j=x/i;
            int n=(i+j)/2;
            int k=(j-i)/2;

            if(k!=0 && f==0 && n/k!=0 && n/(n/k)==k && n*n-k*k==x)
            {
                f=1;
                cout << n << ' ' << n/k << ' ' << endl;
            }
        }

        if(f==0)
            cout << "-1" << endl;
    }
}