#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int x, k;
        cin>>x>>k;
        for(int a=2; a<=k; a++)
        {
            int mi=9, ma=0, t=x;
            while(t)
            {
                int i=t%10;
                mi=min(mi, i), ma=max(ma, i);
                t/=10;
            }
            if(mi==0) break;
            x+=mi*ma;
        }
        cout<<x<<"\n";
    }
}