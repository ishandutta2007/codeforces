#include<bits/stdc++.h>
using namespace std;
const int LEN=100005;
const int N=25;
int t,n,mp[N][N],m,S,vis[N];
char A[LEN],B[LEN];
vector<int> G[N];

namespace DSU{
    int fa[N];
    void init(){for(int i=0;i<20;i++) fa[i]=i,G[i].push_back(i);}
    int getfather(int x){
        if(fa[x]==x) return x;
        return fa[x]=getfather(fa[x]);
    }
    void unite(int x,int y){
        x=getfather(x); y=getfather(y); fa[y]=x;
        if(x==y) return;
        for(int i=0;i<(int)G[y].size();i++) G[x].push_back(G[y][i]);
        G[y].clear();
    }
}

void init()
{
    for(int i=0;i<20;i++) G[i].clear();
    DSU::init();
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    scanf("%s",A+1); scanf("%s",B+1);
    for(int i=1;i<=n;i++) 
    {
        if(A[i]==B[i]) continue;
        mp[A[i]-'a'][B[i]-'a']=1;
        DSU::unite(A[i]-'a',B[i]-'a');
        if(!vis[A[i]-'a']) S++;
        if(!vis[B[i]-'a']) S++;
        vis[A[i]-'a']=1; vis[B[i]-'a']=1;
    }
}

int isdag[1<<20],id[N],reach[N];
int solve(vector<int> V)
{
    int ret=0;
    int m=(int)V.size(),full=(1<<m)-1; 
    for(int i=0;i<m;i++) id[i]=V[i];
    for(int i=0;i<=full;i++) isdag[i]=0;
    for(int i=0;i<m;i++) isdag[1<<i]=1;
    memset(reach,0,sizeof(reach));
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++) if(mp[id[i]][id[j]]) reach[i]|=(1<<j);
    for(int mask=0;mask<=full;mask++)
    {
        if(!isdag[mask]) continue;
        int to=0,tmp=0;
        for(int i=0;i<m;i++)
        {
            if((1<<i)&mask) to|=reach[i],tmp++;
        }
        ret=max(ret,tmp);
        for(int i=0;i<m;i++)
        {
            if(((1<<i)&to)&&(((1<<i)&mask)==0)) 
            {
                if((reach[i]&mask)==0) isdag[mask|(1<<i)]=1;
            }
            if(((1<<i)&to)==0) isdag[mask|(1<<i)]=1;
        }
    }
    return m+m-ret-1;
}

int main()
{
    cin>>t;
    while(t--)
    {
        int ans=0;
        init();
        for(int i=0;i<20;i++) if(DSU::fa[i]==i&&vis[i]) 
        {
            //cout<<i<<":";
            //for(int j=0;j<(int)G[i].size();j++) cout<<G[i][j]<<" "; cout<<endl;
            ans+=solve(G[i]);
        }
        printf("%d\n",ans);
    }
}