#include <bits/stdc++.h>
#define int long long
#define y1 sdofhdodfhd

using namespace std;

int n, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    int Min=1e18;

    for(int i=2;i*i<=b;i++)
        if(b%i==0)
    {
        int k=0;
        while(b%i==0)
        {
            b/=i;
            k++;
        }
        int x=i;
        int y=0;
        while(x<=n)
        {
            y+=n/x;
            if(x>2e18/i)
                x=2e18;
            else
            x*=i;
        }
        Min=min(Min, y/k);
    }

    if(b>1)
    {
        int i=b;
        int k=0;
        while(b%i==0)
        {
            b/=i;
            k++;
        }
        int x=i;
        int y=0;
        while(x<=n)
        {
            y+=n/x;
            if(x>2e18/i)
                x=2e18;
            else x*=i;
        }
        Min=min(Min, y/k);
    }

    cout << Min;
}