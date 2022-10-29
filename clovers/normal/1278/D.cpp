#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
struct node{
    int id,pos,typ;
    node(){}
    node(int id,int pos,int typ):id(id),pos(pos),typ(typ){}
    bool operator < (const node &rhs) const{
        return pos<rhs.pos;
    }
};
pii a[N];
node t[N*2];
int n,sum=0,pos[N*2];
set<int> st;
vector<int> v[N];
int E=0;
int vis[N];
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i];
        if(vis[to]) continue;
        dfs(to);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
        t[i*2-1]=node(i,a[i].first,1);
        t[i*2]=node(i,a[i].second,-1);
        pos[a[i].first]=i; pos[a[i].second]=i;
    }
    sort(t+1,t+n+n+1);
    for(int i=1;i<=n+n;i++)
    {
        if(t[i].typ==1) st.insert(a[t[i].id].first);
        else st.erase(a[pos[t[i].pos]].first);
        set<int>::iterator it;
        if(t[i].typ==-1) for(it=st.upper_bound(a[t[i].id].first);it!=st.end();it++)
        {
            E++; 
            v[pos[*it]].push_back(t[i].id);
            v[t[i].id].push_back(pos[*it]);
            if(E==n)
            {
                puts("NO");
                return 0;
            }
        }
    }
    int bl=1; 
    memset(vis,0,sizeof(vis));
    dfs(1);
    for(int i=1;i<=n;i++) bl&=vis[i];
    if(bl) puts("YES");
    else puts("NO");
    return 0;
}