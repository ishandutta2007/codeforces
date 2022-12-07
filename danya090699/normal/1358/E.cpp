#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n-n/2], su=0, x;
    for(int a=0; a<n-n/2; a++)
    {
        scanf("%lld", &ar[a]);
        su+=ar[a];
    }
    cin>>x;
    if(x>=0)
    {
        if(su+x*(n/2)>0) cout<<n;
        else cout<<-1;
    }
    else
    {
        int k=n;
        for(int a=0; a+k<=n; a++)
        {
            if(su<=0)
            {
                cout<<-1;
                return 0;
            }
            k=min(k, n-n/2-a+(su-1)/(-x));
            if(k<=n/2)
            {
                cout<<-1;
                return 0;
            }
            su-=ar[a];
        }
        cout<<k;
    }
}