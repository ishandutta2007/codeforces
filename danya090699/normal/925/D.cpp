#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9;
vector <int> sv[sz], sp;
bool us[sz];
void dfs(int v)
{
    us[v]=1, sp.push_back(v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    int di[n], pr[n];
    for(int a=0; a<n; a++) di[a]=inf;
    di[0]=0, pr[0]=-1;
    queue <int> qu;
    qu.push(0);
    while(qu.size())
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int v=qu.front();
            for(int b=0; b<sv[v].size(); b++)
            {
                int ne=sv[v][b];
                if(di[ne]==inf)
                {
                    di[ne]=di[v]+1, pr[ne]=v, qu.push(ne);
                }
            }
            qu.pop();
        }
    }
    if(di[n-1]<=4)
    {
        cout<<di[n-1]<<"\n";
        int cu=n-1;
        vector <int> an;
        while(cu!=-1)
        {
            an.push_back(cu+1), cu=pr[cu];
        }
        reverse(an.begin(), an.end());
        for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
    }
    else
    {
        bool fo=0;
        for(int a=0; a<n; a++)
        {
            if(di[a]==2)
            {
                cout<<"4\n";
                cout<<1<<" "<<pr[a]+1<<" "<<a+1<<" "<<1<<" "<<n;
                fo=1;
                break;
            }
        }
        if(fo==0)
        {
            us[0]=1;
            for(int a=0; a<sv[0].size(); a++)
            {
                int v=sv[0][a];
                if(us[v]==0)
                {
                    dfs(v);
                    for(int b=0; b<sp.size(); b++)
                    {
                        int u=sp[b];
                        if(sv[u].size()!=sp.size())
                        {
                            for(int c=0; c<n; c++) us[c]=0;
                            us[u]=1;
                            for(int c=0; c<sv[u].size(); c++) us[sv[u][c]]=1;
                            for(int c=0; c<sv[u].size(); c++)
                            {
                                int ne=sv[u][c];
                                if(ne!=0)
                                {
                                    for(int d=0; d<sv[ne].size(); d++)
                                    {
                                        int u2=sv[ne][d];
                                        if(us[u2]==0)
                                        {
                                            cout<<"5\n";
                                            cout<<1<<" "<<u+1<<" "<<ne+1<<" "<<u2+1<<" "<<u+1<<" "<<n;
                                            fo=1;
                                            break;
                                        }
                                    }
                                }
                                if(fo) break;
                            }
                            break;
                        }
                    }
                    sp.clear();
                    if(fo) break;
                }
            }
            if(fo==0) cout<<-1;
        }
    }
}