#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e13;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int st[n], sp[n];
    for(int a=0; a<n; a++) scanf("%lld", &st[a]);
    for(int a=0; a<n; a++) scanf("%lld", &sp[a]);
    int l=-1, r=inf;
    while(r-l>1)
    {
        int mid=(l+r)>>1, lef=k, ok=1, q[k];
        for(int a=0; a<k; a++) q[a]=0;
        for(int a=0; a<n; a++)
        {
            int cu=st[a], p=0;
            while(lef)
            {
                p+=cu/sp[a], cu%=sp[a];
                if(p>=k-1) break;
                cu+=mid, q[p]++, lef--;
            }
            if(p<k-1) ok=0;
        }
        for(int a=0; a<k; a++)
        {
            if(a) q[a]+=q[a-1];
            if(q[a]>a+1) ok=0;
        }
        if(ok) r=mid;
        else l=mid;
    }
    if(r==inf) cout<<-1;
    else cout<<r;
}