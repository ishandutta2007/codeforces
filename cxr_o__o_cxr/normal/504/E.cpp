//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=3e5+4,mod=1e9+713,B=317;
int n,tim,dep[N],fa[N][20],d[N],h1[N],h2[N],st[N],a[N<<1],son[N],pw[N],top[N],mn[N<<1][20],lg[N<<1];
char s[N];
vector<int>e[N],fu[N],fv[N];
void dfs_1(int x){
	dep[x]=d[x]=d[fa[x][0]]+1;
	h1[x]=((ll)h1[fa[x][0]]*B+s[x])%mod;
	h2[x]=((ll)s[x]*pw[d[x]-1]+h2[fa[x][0]])%mod;
	for(int i=1;(1ll<<i)<=d[x];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	st[x]=++tim;a[tim]=x;
	for(auto v:e[x]){
		if(v==fa[x][0])continue;
		fa[v][0]=x;
		dfs_1(v);
		a[++tim]=x; 
		if(dep[v]>dep[x]){dep[x]=dep[v];son[x]=v;}
	}
}
void dfs_2(int x,int tp){
	top[x]=tp;
	if(x==tp){
		for(int i=0,ou=x,ov=x;i<=dep[x]-d[x];i++,ou=fa[ou][0],ov=son[ov]){
			fu[x].push_back(ou);fv[x].push_back(ov);
		}
	}
	if(son[x])dfs_2(son[x],tp);
	for(auto v:e[x])
		if(v!=fa[x][0]&&v!=son[x])dfs_2(v,v);
}
inline int kthfa(int x,int k){
	if(!k)return x;
	x=fa[x][lg[k]];k-=1<<lg[k];
	k-=d[x]-d[top[x]];x=top[x];
	return k>=0?fu[x][k]:fv[x][-k];
}
inline int cmp(int x,int y){
	return d[a[x]]<d[a[y]]?x:y;
}
inline void prepare(){
	for(int i=2;i<=tim;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=tim;i++)mn[i][0]=i;
	for(int j=1;(1<<j)<=tim;j++)
		for(int i=1;i+(1<<j-1)<=tim;i++)
			mn[i][j]=cmp(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
}
inline int getlca(int u,int v){
	u=st[u];v=st[v];
	if(u>v)u^=v^=u^=v;
	int k=lg[v-u+1];
	return a[cmp(mn[u][k],mn[v-(1<<k)+1][k])];
}
inline int hsh(int u,int lca,int v,int dis){
	int x;
	if(d[u]-d[lca]>=dis){
		x=kthfa(u,dis);
		return (ll)pw[n-dis-d[x]]*(h2[u]-h2[x]+mod)%mod;
	}
	x=kthfa(v,d[u]+d[v]-d[lca]*2+1-dis);
	return ((ll)pw[n-dis+d[x]-d[lca]*2+1]*(h2[u]-h2[lca]+mod)
		+(ll)(h1[x]-(ll)h1[fa[lca][0]]*pw[d[x]-d[lca]+1]%mod+mod)*pw[n-dis])%mod;
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1,u,v;i<n;i++){
		u=read();v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=(ll)pw[i-1]*B%mod;
	dfs_1(1);dfs_2(1,1);
	prepare();
	for(int Q=read(),u1,v1,u2,v2,l1,l2,l,r,mid;Q--;){
		u1=read();v1=read();u2=read();v2=read();
		l1=getlca(u1,v1);l2=getlca(u2,v2);
		l=0;r=min(d[u1]+d[v1]-d[l1]*2+1,d[u2]+d[v2]-d[l2]*2+1);
		while(l<r){
			mid=(l+r+1)>>1;
			if(hsh(u1,l1,v1,mid)==hsh(u2,l2,v2,mid))l=mid;
			else r=mid-1;
		}
		cout<<r<<"\n";
	}
	return (0-0);
}