#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef long long ll;
const int MOD=998244353;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
ll inv(ll num){
	ll t=MOD-2,res=1,ans=num;
	while (t){
		if (t&1){
			res*=ans,t--,res%=MOD;
			continue;
		}
		ans*=ans,ans%=MOD,t>>=1;
	}
	return res;
}
int n,q,cnt;
int siz[150004];
vector<int>g[150004];
int nxt[150004],h[150004],p[150004],cmp[150004],R[150004];
void dfs1(int x,int par){
	siz[x]=1,p[x]=par;
	int maxx=0;
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par){
		dfs1(g[x][i],x),siz[x]+=siz[g[x][i]];
		if(maxx<siz[g[x][i]])maxx=siz[g[x][i]],h[x]=g[x][i];
	}
}
void dfs2(int x,int H,int par){
	cmp[x]=++cnt,nxt[x]=H;
	if(h[x])dfs2(h[x],H,x);
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=h[x]&&g[x][i]!=par)
		dfs2(g[x][i],g[x][i],x);
	R[x]=cnt;
}
int num[150004];
int bit1[150004],bit2[150004];
void upd1(int id,int x){
	while(id){
		if(x>=0)bit1[id]=(bit1[id]+x)%MOD;
		else bit1[id]=(bit1[id]+MOD+x)%MOD;
		id-=(id&-id);
	}
}
void qry1(int l,int r,int x){
	upd1(l-1,-x),upd1(r,x);
}
int got1(int id){
	int ret=0;
	while(id<=n){
		ret=(ret+bit1[id])%MOD;
		id+=(id&-id);
	}
	return ret;
}
int got2(int id){
	int ret=0;
	while(id){
		ret=(ret+bit2[id])%MOD;
		id-=(id&-id);
	}
	return ret;
}
int qry2(int l,int r){
	return (got2(r)-got2(l-1)+MOD)%MOD;
}
void upd2(int id,int x){
	while(id<=n){
		bit2[id]=(bit2[id]+x)%MOD;
		id+=(id&-id);
	}
}
int fans(int u){
	int ret=0;
	while(1){
		int L=nxt[u];
		ret=(ret+qry2(cmp[L],cmp[u]))%MOD;
		if(L==1)return ret;
		ret=(1ll*num[p[L]]*(MOD-siz[L])%MOD+ret)%MOD;
		u=p[L];
	}
}
int main(){
	read(n),read(q);
	for(int i=1;i<n;i++){
		int u,v;read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs1(1,-1);
	dfs2(1,1,-1);
	const ll INV=inv(n);
	while(q--){
		int opt,x,d;
		read(opt);
		if(opt==1){
			read(x),read(d);
			int ts=1ll*d*siz[x]%MOD,tn=1ll*d*n%MOD;
			qry1(1,n,ts);
			qry1(cmp[x],R[x],-ts);
			qry1(cmp[x],R[x],tn);
			num[x]=(num[x]+d)%MOD;
			if(h[x]){
				int tz=1ll*d*(MOD-siz[h[x]])%MOD; 
				upd2(cmp[h[x]],tz);	
			}
		}else{
			read(x);
			int num1=(got1(cmp[x])+fans(x))%MOD;
			write(num1*INV%MOD),puts("");
		}
	}
}