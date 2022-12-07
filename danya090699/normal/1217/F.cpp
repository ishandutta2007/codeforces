#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, bl=2000;
vector <pair <int, int> > sv[sz];
vector <pair <pair <int, int>, int > > sv2[sz];
int cnu[sz], qu[sz], us[sz], us2[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, last=0;
    cin>>n>>m;
    int sp[m][3];
    set <int> se[n];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<3; b++) scanf("%d", &sp[a][b]);
        sp[a][1]--, sp[a][2]--;

        if(sp[a][0]==1)
        {
            for(int i=0; i<2; i++)
            {
                int u=(sp[a][1]+i)%n, v=(sp[a][2]+i)%n;
                se[u].insert(v), se[v].insert(u);
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        for(auto it=se[a].begin(); it!=se[a].end(); it++) sv[a].push_back({*it, 0});
    }
    for(int a=0; a<m; a+=bl)
    {
        map <pair <int, int>, bool > re;
        for(int b=a; b<min(a+bl, m); b++)
        {
            if(sp[b][0]==1)
            {
                for(int i=0; i<2; i++)
                {
                    int u=(sp[b][1]+i)%n, v=(sp[b][2]+i)%n;
                    if(u>v) swap(u, v);
                    if(re.find({u, v})==re.end())
                    {
                        auto it=lower_bound(sv[u].begin(), sv[u].end(), make_pair(v, 0));
                        if((*it).second)
                        {
                            (*it).second=0;
                            it=lower_bound(sv[v].begin(), sv[v].end(), make_pair(u, 0));
                            (*it).second=0;
                            re[{u, v}]=1;
                        }
                        else re[{u, v}]=0;
                    }
                }
            }
        }
        int cq=0, lg, rg;
        for(int b=0; b<n; b++) cnu[b]=-1, us[b]=0;
        for(int b=0; b<n; b++)
        {
            if(cnu[b]==-1)
            {
                cnu[b]=cq;
                qu[0]=b, lg=0, rg=1;
                while(lg<rg)
                {
                    int v=qu[lg++];
                    for(int c=0; c<sv[v].size(); c++)
                    {
                        int ne=sv[v][c].first;
                        if(sv[v][c].second and cnu[ne]==-1) cnu[ne]=cq, qu[rg++]=ne;
                    }
                }
                cq++;
            }
        }
        for(auto it=re.begin(); it!=re.end(); it++)
        {
            int u=(*it).first.first, v=(*it).first.second;
            bool is=(*it).second;
            if(cnu[u]!=cnu[v])
            {
                sv2[cnu[u]].push_back({{u, v}, is});
                sv2[cnu[v]].push_back({{u, v}, is});
            }
        }
        for(int b=a; b<min(a+bl, m); b++)
        {
            int u=(sp[b][1]+last)%n, v=(sp[b][2]+last)%n;
            if(u>v) swap(u, v);
            if(sp[b][0]==1)
            {
                re[{u, v}]^=1;
                if(cnu[u]!=cnu[v])
                {
                    auto it=lower_bound(sv2[cnu[u]].begin(), sv2[cnu[u]].end(), make_pair(make_pair(u, v), 0));
                    (*it).second^=1;
                    it=lower_bound(sv2[cnu[v]].begin(), sv2[cnu[v]].end(), make_pair(make_pair(u, v), 0));
                    (*it).second^=1;
                }
            }
            else
            {
                u=cnu[u], v=cnu[v], last=0, lg=0, rg=1;
                qu[0]=u, us[u]=1, us2[0]=u;
                int yk=1;
                while(lg<rg)
                {
                    int cu=qu[lg++];
                    if(cu==v)
                    {
                        last=1;
                        break;
                    }
                    for(int c=0; c<sv2[cu].size(); c++)
                    {
                        if(sv2[cu][c].second)
                        {
                            int ne=cnu[sv2[cu][c].first.first];
                            if(us[ne]==0) us[ne]=1, us2[yk++]=ne, qu[rg++]=ne;

                            ne=cnu[sv2[cu][c].first.second];
                            if(us[ne]==0) us[ne]=1, us2[yk++]=ne, qu[rg++]=ne;
                        }
                    }
                }

                printf("%d", last);

                for(int c=0; c<yk; c++) us[us2[c]]=0;
            }
        }
        for(auto it=re.begin(); it!=re.end(); it++)
        {
            int u=(*it).first.first, v=(*it).first.second;
            if((*it).second)
            {
                auto it=lower_bound(sv[u].begin(), sv[u].end(), make_pair(v, 0));
                (*it).second=1;
                it=lower_bound(sv[v].begin(), sv[v].end(), make_pair(u, 0));
                (*it).second=1;
            }
            if(cnu[u]!=cnu[v])
            {
                sv2[cnu[u]].pop_back(), sv2[cnu[v]].pop_back();
            }
        }
    }
}