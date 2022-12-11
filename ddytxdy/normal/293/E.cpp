#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
const int N=1e5+50;
int n,m,p,cnt;
vector<pii>v[N];
vector<int>f[N];
struct node{int l,w,z;bool friend operator <(node a,node b){return a.w<b.w;}}a[N];
int sum,dat,rt,sz[N],Z,mx;bool vis[N];LL ans;
void add(int x,int y,int z){if(!y)f[x][y]+=z;else for(int i=y;i<f[x].size();i+=i&-i)f[x][i]+=z;}
int ask(int x,int y){int z=0;for(int i=min(y,(int)f[x].size()-1);i>0;i-=i&-i)z+=f[x][i];return z+(y>=0?f[x][0]:0);}
void findr(int x,int ff){
	int mx=0;sz[x]=1;
	for(int i=0,y;i<v[x].size();i++)
		if(!vis[y=v[x][i].first]&&y!=ff)
			findr(y,x),sz[x]+=sz[y],mx=max(mx,sz[y]);
	mx=max(mx,sum-sz[x]);if(mx<dat)dat=mx,rt=x;
}
void dfs(int x,int ff,int d,int w){
    a[++cnt]=(node){d,w,Z};mx=max(mx,d);
    for(int i=0,y;i<v[x].size();i++)
        if(!vis[y=v[x][i].first]&&y!=ff)
            dfs(y,x,d+1,w+v[x][i].second);
}
void solve(int x){
	vis[x]=1;a[cnt=1]=(node){0,0,x};f[x].resize(1);
    for(int i=0,y;i<v[x].size();i++)
        if(!vis[y=v[x][i].first])Z=y,mx=0,dfs(y,x,1,v[x][i].second),f[y].resize(mx+1);
    sort(a+1,a+cnt+1);int j=0;
    for(int i=cnt;i;i--){
        while(j<i-1&&a[j+1].w+a[i].w<=p)
            j++,add(0,a[j].l,1),add(a[j].z,a[j].l,1);
        if(j==i)add(0,a[j].l,-1),add(a[j].z,a[j].l,-1),j--;
        ans+=ask(0,m-a[i].l)-ask(a[i].z,m-a[i].l);
    }
	for(int i=0,y;i<v[x].size();i++)if(!vis[y=v[x][i].first])
		sum=sz[y],dat=1e9,findr(y,x),solve(rt);
}
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=2,x,y;i<=n;i++)
        scanf("%d%d",&x,&y),
        v[x].pb(mp(i,y)),v[i].pb(mp(x,y));
    f[0].resize(n);sum=n;dat=1e9;findr(1,0);solve(rt);
    cout<<ans;
    return 0;
}