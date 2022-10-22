#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
const int mod=1e9+7;
const int B=2329207;
int n,m;
int anc[N][20],lg[N];
vector<int> g[N],dn[N],up[N];
int dep[N],son[N],h[N],top[N];
int ha0[N],ha1[N],pb[N],ipb[N];
char a[N];
void dfs1(int u){
	for(int i=1;i<20;i++)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	h[u]=h[anc[u][0]]+1;
	ha0[u]=(1ll*ha0[anc[u][0]]*B+a[u])%mod;
	ha1[u]=(ha1[anc[u][0]]+1ll*a[u]*pb[h[u]])%mod;
	for(auto v:g[u]){
		if(v==anc[u][0]) continue;
		anc[v][0]=u;
		dfs1(v);
		if(dep[v]+1>dep[u]){
			dep[u]=dep[v]+1;
			son[u]=v;
		}
	}
}
void dfs2(int u,int tp){
	top[u]=tp;
	for(auto v:g[u]){
		if(v==anc[u][0]) continue;
		if(v==son[u]) dfs2(v,tp);
		else dfs2(v,v);
	}
}
inline int kanc(int u,int k){
	if(k>=h[u]) return 0;
	if(k==0) return u;
	int c=top[anc[u][lg[k]]];
	if(h[u]-h[c]>=k) return dn[c][h[u]-h[c]-k];
	else return up[c][k-h[u]+h[c]-1];
}
inline int get(int u,int v,int c,int x){
	if(x<=h[u]-h[c]+1){
		int t=kanc(u,x);
		return (ha0[u]-1ll*ha0[t]*pb[h[u]-h[t]]%mod+mod)%mod;
	}
	int t=kanc(v,(h[u]+h[v]-2*h[c]+1)-x);
	int w0=(ha0[u]-1ll*ha0[anc[c][0]]*pb[h[u]-h[c]+1]%mod+mod)%mod;
	int w1=ll(ha1[t]-ha1[c]+mod)*ipb[h[c]+1]%mod;
	return (w0+1ll*w1*pb[h[u]-h[c]+1])%mod;
}
inline int lca(int x,int y){
	int i;
	if(h[x]<h[y]) swap(x,y);
	for(i=19;i>=0;i--){
		if(h[anc[x][i]]>=h[y])
			x=anc[x][i];
	}
	if(x==y) return x;
	for(i=19;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
inline int po(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j;
	cin>>n;
	cin>>(a+1);
	for(i=1;i<=n;i++) a[i]-='a'-1;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	pb[0]=1;
	for(i=1;i<=n;i++) pb[i]=1ll*pb[i-1]*B%mod;
	ipb[0]=1;ipb[1]=po(B,mod-2);
	for(i=2;i<=n;i++) ipb[i]=1ll*ipb[i-1]*ipb[1]%mod;
	dfs1(1);
	dfs2(1,1);
	for(i=1;i<=n;i++){
		if(top[i]==i){
			for(j=i;j;j=son[j]) dn[i].push_back(j);
			for(j=anc[i][0];j&&up[i].size()<=dn[i].size();j=anc[j][0])
				up[i].push_back(j);
		}
	}
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
	cin>>m;
	while(m--){
		int a,b,c,d;cin>>a>>b>>c>>d;
		int x=lca(a,b),y=lca(c,d);
		int l=0,r=min(h[a]+h[b]-2*h[x]+1,h[c]+h[d]-2*h[y]+1);
		while(l<r){
			int mid=l+r+1>>1;
			if(get(a,b,x,mid)==get(c,d,y,mid)) l=mid;
			else r=mid-1;
		}
		cout<<l<<'\n';
	}
	return 0;
}