#include <bits/stdc++.h>
using namespace std;
struct re
{
    int to, a, b, rev, us;
};
vector <re> sv[1<<20];
vector <int> sp;
void dfs(int v)
{
    while(sv[v].size())
    {
        re &e=sv[v].back();
        int to=e.to, A=e.a, B=e.b, rev=e.rev, us=e.us;
        sv[v].pop_back();
        if(!us)
        {
            sv[to][rev].us=1;
            dfs(to);
            sp.push_back(B);
            sp.push_back(A);
        }
    }
    /*for(int a=0; a<sv[v].size(); a++)
    {
        re &e=sv[v][a];
        if(!e.us)
        {
            e.us=1, sv[e.to][e.rev].us=1;
            dfs(e.to);
            sp.push_back(e.b);
            sp.push_back(e.a);
        }
    }*/
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) scanf("%d%d", &ar[a].first, &ar[a].second);
    int l=-1, r=21;
    vector <int> an;
    while(r-l>1)
    {
        int mid=(l+r)>>1, x=(1<<mid)-1;
        for(int a=0; a<n; a++)
        {
            int u=(ar[a].first&x), v=(ar[a].second&x);
            if(u!=v)
            {
                sv[u].push_back({v, a*2+1, a*2+2, sv[v].size(), 0});
                sv[v].push_back({u, a*2+2, a*2+1, sv[u].size()-1, 0});
            }
            else
            {
                sv[u].push_back({u, a*2+1, a*2+2, sv[u].size()+1, 0});
                sv[u].push_back({u, a*2+2, a*2+1, sv[u].size()-1, 0});
            }
            //cout<<u<<" "<<v<<"\n";
        }
        bool ok=1;
        for(int a=0; a<(1<<mid); a++) if(sv[a].size()&1) ok=0;
        if(ok)
        {
            //cout<<"!";
            for(int a=0; a<(1<<mid); a++)
            {
                if(sv[a].size())
                {
                    dfs(a);
                    break;
                }
            }
            //cout<<sp.size()<<"\n";
            if(sp.size()==n*2) an=sp;
            else ok=0;
        }
        if(ok) l=mid;
        else r=mid;

        sp.clear();
        for(int a=0; a<(1<<mid); a++) sv[a].clear();
    }
    cout<<l<<"\n";
    for(int a=0; a<n*2; a++) printf("%d ", an[a]);
}