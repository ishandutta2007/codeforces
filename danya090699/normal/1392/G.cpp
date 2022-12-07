#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    string s, t;
    cin>>s>>t;
    int to[k], mi[1<<k], ma[1<<k];
    for(int a=0; a<k; a++) to[a]=a;
    for(int mask=0; mask<(1<<k); mask++) mi[mask]=inf, ma[mask]=-inf;
    for(int a=0; a<=n; a++)
    {
        if(a)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            i--, j--;
            swap(to[i], to[j]);
        }
        int lmask=0, rmask=0;
        for(int b=0; b<k; b++)
        {
            if(s[b]=='1') lmask+=(1<<to[b]);
            if(t[b]=='1') rmask+=(1<<to[b]);
        }
        mi[lmask]=min(mi[lmask], a);
        ma[rmask]=max(ma[rmask], a);
    }
    int an=-1, l, r;
    for(int mask=(1<<k)-1; mask>=0; mask--)
    {
        for(int i=0; i<k; i++)
        {
            if((mask&(1<<i))==0)
            {
                mi[mask]=min(mi[mask], mi[mask+(1<<i)]);
                ma[mask]=max(ma[mask], ma[mask+(1<<i)]);
            }
        }
        if(ma[mask]-mi[mask]>=m and __builtin_popcount(mask)>an)
        {
            an=__builtin_popcount(mask), l=mi[mask]+1, r=ma[mask];
        }
    }
    int q=0;
    for(int a=0; a<k; a++)
    {
        if(s[a]=='1') q++;
        if(t[a]=='1') q++;
    }
    cout<<k-q+2*an<<"\n"<<l<<" "<<r;
}