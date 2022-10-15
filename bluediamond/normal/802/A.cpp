#include <bits/stdc++.h>

using namespace std;

const int N=80+5;

int n,mx;
int now=0;
bool active[N];
int v[N];
int res=0;

vector<int>pp[N];
int it[N];

set<pair<int,int>>act;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>mx;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        pp[v[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        pp[i].push_back((1<<30));
    }
    for(int i=1;i<=n;i++)
    {
        int x=v[i];
        it[x]++;
        if(active[x])
        {
            int ini=pp[x][it[x]-1];
            act.erase({-ini,x});
            int noww=pp[x][it[x]];
            act.insert({-noww,x});
            continue;
        }
        if(now==mx)
        {
            res++;
            auto it=*act.begin();
            int who=it.second;
            act.erase(it);
            active[who]=0;
            active[x]=1;
        }
        else
        {
            now++;
            res++;
            active[x]=1;
        }
        int noww=pp[x][it[x]];
        act.insert({-noww,x});
    }
    cout<<res<<"\n";
    return 0;
}