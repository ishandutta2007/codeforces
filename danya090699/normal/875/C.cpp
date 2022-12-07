#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int n, m, ok=1, us[sz];
void dfs(int v)
{
    us[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==-1) dfs(ne);
        else if(us[ne]==1) ok=0;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    vector <int> wo[n];
    for(int a=0; a<m; a++) us[a]=-1;
    for(int a=0; a<n; a++)
    {
        int q;
        cin>>q;
        wo[a].resize(q);
        for(int b=0; b<q; b++)
        {
            cin>>wo[a][b];
            wo[a][b]--;
        }
    }
    for(int a=0; a<n-1; a++)
    {
        int fo=0, le=min(wo[a].size(), wo[a+1].size());
        for(int b=0; b<le; b++)
        {
            int l=wo[a][b], r=wo[a+1][b];
            if(l!=r)
            {
                if(l<r) sv[r].push_back(l);
                else
                {
                    if(us[l]!=1 and us[r]!=0)
                    {
                        us[l]=0, us[r]=1;
                    }
                    else ok=0;
                }
                fo=1;
                break;
            }
        }
        if(fo==0 and wo[a].size()>wo[a+1].size()) ok=0;
    }
    if(ok)
    {
        for(int a=0; a<m; a++)
        {
            if(us[a]==0) dfs(a);
        }
        if(ok)
        {
            vector <int> an;
            for(int a=0; a<m; a++)
            {
                if(us[a]==0) an.push_back(a+1);
            }
            cout<<"Yes\n"<<an.size()<<"\n";
            for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
        }
        else cout<<"No";
    }
    else cout<<"No";
}