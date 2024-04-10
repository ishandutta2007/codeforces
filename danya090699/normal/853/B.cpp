//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <pair <int, int> > fr[sz], to[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    long long pr[sz], pr2[sz], cu=0, inf=1e18;
    int be[n], q=0;
    for(int a=0; a<n; a++) be[a]=-1;
    for(int a=0; a<m; a++)
    {
        int d, f, t, c;
        scanf("%d%d%d%d", &d, &f, &t, &c);
        if(f!=0) fr[d].push_back(make_pair(f-1, c));
        else to[d].push_back(make_pair(t-1, c));
    }
    for(int a=0; a<sz; a++)
    {
        for(int b=0; b<fr[a].size(); b++)
        {
            int nu=fr[a][b].first, va=fr[a][b].second;
            if(be[nu]==-1)
            {
                be[nu]=va, cu+=va, q++;
            }
            else if(va<be[nu])
            {
                cu+=va-be[nu], be[nu]=va;
            }
        }
        if(q<n) pr[a]=-1;
        else pr[a]=cu;
    }
    cu=0, q=0;
    for(int a=0; a<n; a++) be[a]=-1;
    for(int a=sz-1; a>=0; a--)
    {
        for(int b=0; b<to[a].size(); b++)
        {
            int nu=to[a][b].first, va=to[a][b].second;
            if(be[nu]==-1)
            {
                be[nu]=va, cu+=va, q++;
            }
            else if(va<be[nu])
            {
                cu+=va-be[nu], be[nu]=va;
            }
        }
        if(q<n) pr2[a]=-1;
        else pr2[a]=cu;
    }
    long long ans=inf;
    for(int a=0; a<sz; a++)
    {
        if(a+k+1<sz)
        {
            if(pr[a]!=-1 and pr2[a+k+1]!=-1) ans=min(ans, pr[a]+pr2[a+k+1]);
        }
    }
    if(ans==inf) cout<<-1;
    else cout<<ans;
}