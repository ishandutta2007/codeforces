#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin>>m>>n;
    bool tr[n], fo=0;
    for(int a=0; a<n; a++)
    {
        cout<<1<<"\n";
        int re;
        cin>>re;
        if(re==0)
        {
            fo=1;
            break;
        }
        if(re==1) tr[a]=1;
        else tr[a]=0;
    }
    if(fo==0)
    {
        int l=0, r=m+1, nu=0;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            cout<<mid<<"\n";
            int re;
            cin>>re;
            if(re==0)
            {
                break;
            }

            if(tr[nu]==0) re*=-1;
            nu=(nu+1)%n;

            if(re==1) l=mid;
            else r=mid;
        }
    }
}