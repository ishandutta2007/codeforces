#include <bits/stdc++.h>

using namespace std;

const int N=5000;

int n,m,s;
vector<int>v[N+5];
bool viz[N+5];
int cur[N+5];
int cnt=0,cate[N+5];

void dfs(int nod)
{
    viz[nod]=1;
    for(auto nou:v[nod])
    {
        if(viz[nou]==0)
            dfs(nou);
    }
}

int ind;

void dfs2(int nod)
{
  ///  cout<<nod<<"\n";
    cnt++;
    cur[nod]=ind;
    for(auto nou:v[nod])
    {
        if(viz[nou]==0 && cur[nou]!=ind)
            dfs2(nou);
    }
}

struct info
{
    int ind,val;
};

bool cmp(info a,info b)
{
    return a.val>b.val;
}

info sl[N+5];
int y=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    dfs(s);
    for(int i=1;i<=n;i++)
        if(viz[i]==0)
        {
            cnt=0;
            ind=i;
            dfs2(i);
            sl[++y]={i,cnt};
        }
    sort(sl+1,sl+y+1,cmp);
    int cost=0;
    for(int i=1;i<=y;i++)
    {
        int nod=sl[i].ind;
        if(viz[nod]==1)
            continue;
        dfs(nod);
        cost++;
    }
    cout<<cost<<"\n";
    return 0;
}
/**
**/