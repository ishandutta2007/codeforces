#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int a=0; a<t; a++)
    {
        int x, y, p, q;
        cin>>x>>y>>p>>q;
        int l=0, r=2e9, pos=0;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            int add1=p*mid-x, add2=q*mid-y;
            if(add1>=0 and add2>=0)
            {
                if(add2>=add1)
                {
                    pos=1, r=mid;
                }
                else l=mid;
            }
            else l=mid;
        }
        if(pos==0) cout<<-1<<"\n";
        else cout<<(q*r-y)<<"\n";
    }
}