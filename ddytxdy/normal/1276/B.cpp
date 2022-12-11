#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=200500,M=500050;
int t,n,m,a,b,x,y,ver[M*2],nxt[M*2],head[N],tot,dfn[N],low[N],cnt,flag,sum,d1,d2;bool is[N],vis[N];LL ans;
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void dfs(int x,int r){
	dfn[x]=low[x]=++cnt;
	int num=0;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(!dfn[y]){
			dfs(y,0);
			low[x]=min(low[x],low[y]);
			if(low[y]==dfn[x])num++;
		}
		else low[x]=min(low[x],dfn[y]);
	}
	if((!r&&num)||num>1)is[x]=1;
}
void dfs(int x){
    vis[x]=1;sum++;
    for(int i=head[x],y;i;i=nxt[i])
        if(!vis[y=ver[i]]){
            if(y==a)flag|=1;
            else if(y==b)flag|=2;
            else dfs(y);
        }
}
void solve(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=n;i++)head[i]=dfn[i]=is[i]=vis[i]=0;tot=cnt=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
    dfs(1,1);d1=d2=0;
    if(!is[a]&&!is[b]){puts("0");return;}
    for(int i=1;i<=n;i++){
        if(i!=a&&i!=b&&!vis[i]){
            flag=0;sum=0;dfs(i);
            if(flag==1)d1+=sum;
            if(flag==2)d2+=sum;
        }
    }
    cout<<1ll*d1*d2<<endl;
}
int main(){
	scanf("%d",&t);
    while(t--)solve();
	return 0;
}