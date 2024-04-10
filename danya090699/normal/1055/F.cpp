#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10;
vector <pair <int, int> > sv[sz];
int h[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        h[ne]=h[v]^w, dfs(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    for(int a=1; a<n; a++)
    {
        int pr, w;
        scanf("%lld%lld", &pr, &w);
        pr--, sv[pr].push_back({a, w});
    }
    dfs(0);
    sort(h, h+n);
    int l[n], r[n], su=0, an=0;
    for(int a=0; a<n; a++) l[a]=0, r[a]=n;
    for(int i=61; i>=0; i--)
    {
        int mid[n], q=0;
        for(int a=0; a<n; a++) mid[a]=-1;
        for(int a=0; a<n; a++)
        {
            int lg=l[a], rg=r[a];
            if(lg!=rg)
            {
                if(mid[lg]==-1)
                {
                    mid[lg]=lg;
                    while(mid[lg]<r[a])
                    {
                        if(h[mid[lg]]&(1ll<<i)) break;
                        else mid[lg]++;
                    }
                }
                if(h[a]&(1ll<<i)) q+=rg-mid[lg];
                else q+=mid[lg]-lg;
            }
        }
        int add=0;
        if(su+q<=k-1) add=1;
        for(int a=0; a<n; a++)
        {
            int lg=l[a], rg=r[a], cu=((h[a]&(1ll<<i))>0);
            if(lg!=rg)
            {
                if(cu^add) l[a]=mid[lg];
                else r[a]=mid[lg];
            }
        }
        if(su+q<=k-1) su+=q, an+=(1ll<<i);
    }
    cout<<an;
}