#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=300000+5;

int n;
vector<int>g[N];
vector<pair<int,int>>info[N];

ll ans[N];
ll sub[N];

bool viz[N];

inline void dfs(int nod,int h,ll now)
{
    viz[nod]=1;
    for(auto &itr:info[nod])
    {
        int d=itr.first;
        int x=itr.second;
        now+=x;
        if(h+d+1<N)
        {
            sub[h+d+1]+=x;
        }
    }
    now-=sub[h];
    ans[nod]=now;
    for(auto &nou:g[nod])
    {
        if(viz[nou]==0)
        {
            dfs(nou,h+1,now);
        }
    }
    for(auto &itr:info[nod])
    {
        int d=itr.first;
        int x=itr.second;
        if(h+d+1<N)
        {
            sub[h+d+1]-=x;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int nod,d,x;
        cin>>nod>>d>>x;
        info[nod].push_back({d,x});
    }
    dfs(1,0,0LL);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**



**/