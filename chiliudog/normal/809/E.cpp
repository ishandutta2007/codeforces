#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x)  for(int i=head[x];i!=-1;i=ne[i])
#define pb push_back
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}x*=f;
}
inline void judge(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}
typedef long long i64;
const int maxn=200005;
const int mod=1e9+7;
int num,n,head[maxn],t[maxn<<1],ne[maxn<<1];
int miu[maxn],prime[maxn],prtot,phi[maxn];
int a[maxn],inva[maxn];
bool flag[maxn];
int tme,deep[maxn],fa[maxn][20],l[maxn],r[maxn];
inline void dfs(int x){
	rep(i,1,19)fa[x][i]=fa[fa[x][i-1]][i-1];
	l[x]=++tme;
	forE(i,x)if(t[i]!=fa[x][0]){
		fa[t[i]][0]=x;deep[t[i]]=deep[x]+1;
		dfs(t[i]);
	}r[x]=tme;
}
inline int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	int dep=deep[x]-deep[y];
	rep(i,0,19)if((1<<i)&dep)x=fa[x][i];
	if(x==y)return x;
	per(i,19,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void prprpr(){
	memset(flag,1,sizeof(flag));phi[1]=1;
	rep(i,2,n){
		if(flag[i]){prime[++prtot]=i;phi[i]=i-1;miu[i]=-1;}
		rep(j,1,prtot){
			if(i*prime[j]>n)break;
			flag[i*prime[j]]=0;
			if(i%prime[j]==0){
				miu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*(prime[j]);
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);miu[i*prime[j]]=-miu[i];
		}
	}
}
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
int v[maxn];
inline bool isson(int x,int y){return l[x]<=l[y]&&r[y]<=r[x];}
inline bool cmp(int x,int y){return l[x]<l[y];}
int h[maxn<<1],tot;
vector<int> son[maxn];
vector<int> dis[maxn];
bool app[maxn];
int S[maxn<<1],top;
int sumphi[maxn],sum[maxn];
int res=0;
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline int dp(int x,int f){
	sumphi[x]=app[x]*phi[a[x]];sum[x]=0;
	for(unsigned j=0;j<son[x].size();j++){
		int v=son[x][j];if(v==f)continue;
		dp(v,x);
		sum[v]=(sum[v]+1ll*sumphi[v]*dis[x][j])%mod;
		res=(res+1ll*sum[v]*sumphi[x])%mod;
		res=(res+1ll*sum[x]*sumphi[v])%mod;
		sum[x]=(sum[x]+sum[v])%mod;
		sumphi[x]=(sumphi[x]+sumphi[v])%mod;
	}
}
inline int calc(int x){
	tot=0;res=0;
	for(int i=x;i<=n;i+=x)h[++tot]=inva[i],app[h[tot]]=1;
	sort(h+1,h+1+tot,cmp);int tmp=tot;
	rep(i,1,tmp-1)h[++tot]=lca(h[i],h[i+1]);tmp=tot;tot=0;h[0]=-1;
	sort(h+1,h+1+tmp,cmp);
	rep(i,1,tmp)if(h[i]!=h[tot])h[++tot]=h[i];S[top=1]=1;int st=1;if(h[1]==1)st=2;
	rep(i,st,tot){
		while(top&&!isson(S[top],h[i]))top--;
		son[h[i]].pb(S[top]);son[S[top]].pb(h[i]);
		dis[h[i]].pb(deep[h[i]]-deep[S[top]]);dis[S[top]].pb(deep[h[i]]-deep[S[top]]);
		S[++top]=h[i];
	}
	dp(1,-1);
	son[1].clear();dis[1].clear();
	rep(i,1,tmp)
		son[h[i]].clear(),dis[h[i]].clear();
	for(int i=x;i<=n;i+=x)app[inva[i]]=0;
	return res;
}
int f[maxn];
int main(){
	read(n);prprpr();
	rep(i,1,n)read(a[i]),inva[a[i]]=i;
	rep(i,1,n)head[i]=-1;
	rep(i,1,n-1){
		int x,y;read(x);read(y);
		addedge(x,y);
	}dfs(1);
	rep(i,1,n)v[i]=calc(i);int res=0;
	per(i,n,1){
		f[i]=v[i];
		for(int j=i+i;j<=n;j+=i)f[i]=(f[i]-f[j]+mod)%mod;
		res=(res+1ll*f[i]*i%mod*powmod(phi[i],mod-2)%mod)%mod;
	}
	res=1ll*2*res%mod;
	res=1ll*res*powmod(n,mod-2)%mod;
	res=1ll*res*powmod(n-1,mod-2)%mod;
	cout<<res<<endl;
}