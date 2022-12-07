#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int va[n*2], us[n*2], del[n*2];
    for(int a=0; a<n*2; a++)
    {
        cin>>va[a];
        us[a]=0, del[a]=0;
    }
    vector <pair <int, int> > sp;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        us[u]=1, us[v]=1;
        if(va[u]<va[v]) swap(u, v);
        sp.push_back({u, v});
    }
    set <pair <int, int>, greater <pair <int, int> > > se;
    for(int a=0; a<n*2; a++) if(us[a]==0) se.insert({va[a], a});
    int t, turn;
    cin>>t;
    for(int a=0; a<n; a++)
    {
        if(t==2)
        {
            cin>>turn;
            turn--, del[turn]=1;
            se.erase({va[turn], turn});
        }
        int fo=0;
        for(int b=0; b<sp.size(); b++)
        {
            int u=sp[b].first, v=sp[b].second;
            if(del[u]+del[v]==1)
            {
                fo=1;
                if(del[u])
                {
                    del[v]=1;
                    cout<<v+1<<endl;
                }
                else
                {
                    del[u]=1;
                    cout<<u+1<<endl;
                }
            }
        }
        if(fo==0)
        {
            int be=-1, beu;
            for(int b=0; b<sp.size(); b++)
            {
                int u=sp[b].first, v=sp[b].second;
                if(del[u]==0 and del[v]==0)
                {
                    if(va[u]-va[v]>=be) be=va[u]-va[v], beu=u;
                }

            }
            if(se.size())
            {
                auto it=se.begin();
                int x=(*it).first, u=(*it).second;
                it++;
                x-=(*it).first;
                if(x>be) beu=u;
            }
            del[beu]=1;
            se.erase({va[beu], beu});
            cout<<beu+1<<endl;
        }

        if(t==1)
        {
            cin>>turn;
            turn--, del[turn]=1;
            se.erase({va[turn], turn});
        }
    }
}