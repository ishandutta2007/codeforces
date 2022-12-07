#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    int l=-1, r=m;
    while(r-l>1)
    {
        int mid=(l+r)>>1, pr=0, ok=1;
        for(int a=0; a<n; a++)
        {

            int ma=(ar[a]+mid)%m;
            //if(mid==1) cout<<ma<<" "<<pr<<"\n";
            if(ma>=ar[a])
            {
                if(ma>=pr) pr=max(pr, ar[a]);
                else ok=0;
            }
            else
            {
                if(pr>ma) pr=max(pr, ar[a]);
            }
        }
        if(ok) r=mid;
        else l=mid;
    }
    cout<<r;
}