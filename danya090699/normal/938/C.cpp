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
        int x;
        cin>>x;
        if(x==0) cout<<"1 1\n";
        else
        {
            bool fo=0;
            for(int m=1; ; m++)
            {
                //cout<<m<<" ";
                if(x<=m*m)
                {
                    int le=m*m-x;
                    if(le>x) break;
                    int l=1, r=m+1;
                    while(r-l>1)
                    {
                        int mid=(l+r)>>1;
                        int q=(m/mid)*(m/mid);
                        if(q>=le) l=mid;
                        else r=mid;
                    }
                    if((m/l)*(m/l)==le)
                    {
                        cout<<m<<" "<<l<<"\n";
                        fo=1;
                        break;
                    }
                }
            }
            if(fo==0) cout<<"-1\n";
        }
    }
}