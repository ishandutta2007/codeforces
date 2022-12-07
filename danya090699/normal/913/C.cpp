#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, ll;
    cin>>n>>ll;
    int pr[n];
    for(int a=0; a<n; a++) cin>>pr[a];
    for(int a=n-1; a>=0; a--) pr[a]=min(pr[a], pr[a+1]);
    for(int a=1; a<n; a++) pr[a]=min(pr[a], pr[a-1]*2);
    int l=0, r=inf;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int q=0, le=mid;
        for(int a=n-1; a>=0; a--)
        {
            int add=(1ll<<a);
            if(inf/add<(le/pr[a])) q+=inf;
            else q+=(le/pr[a])*add;
            if(q>=inf) break;
            le%=pr[a];
        }
        if(q>=ll) r=mid;
        else l=mid;
    }
    cout<<r;
}