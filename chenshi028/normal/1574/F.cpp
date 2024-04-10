#include<cstdio>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
const int o=1.2e6,MOD=998244353;
inline int fix(int x){return x+(x>>31&MOD);}
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,m,K,a[o],pre[o],nxt[o],rev[o],bt,w[o];bool ban[o],vis[o];vector<int> f,g;map<int,int> e[o];
inline void init(){
	bt=20;
	w[1<<(bt-1)]=1;
	for(int i=(1<<(bt-1)),j=qp(3,(MOD-1)/(1<<bt));i<(1<<bt);++i) w[i+1]=w[i]*1ll*j%MOD;
	for(int i=(1<<(bt-1));--i;) w[i]=w[i<<1];
}
inline void ntt(vector<int>&a,int n,bool inv){
	for(int i=1;i<n;++i) if((rev[i]=(rev[i>>1]>>1)|((i&1)<<(bt-1)))<i) swap(a[i],a[rev[i]]);
	for(int md=1;md<n;md<<=1) for(int i=0;i<n;i+=md<<1) for(int j=0,x,y;j<md;++j)
		x=a[i+j],y=a[i+j+md]*1ll*w[j+md]%MOD,a[i+j]=fix(x+y-MOD),a[i+j+md]=fix(x-y);
	if(inv) for(int i=1,j=n-1;i<j;swap(a[i++],a[j--]));
}
inline void Inv(vector<int>&a,int n,vector<int>&b){
	for(bt=0;(1<<bt)<n;++bt);
	a.resize(1<<bt);b=vector<int>(1<<bt,0);
	vector<int> t(1<<bt+1,0),h(1<<bt+1,0);
	b[0]=qp(a[0],MOD-2);
	int Bt=bt;
	for(bt=2;bt<=Bt+1;++bt){
		for(int i=0;i<(1<<bt-1);++i) h[i]=b[i],t[i]=a[i];
		ntt(h,1<<bt,0);ntt(t,1<<bt,0);
		for(int i=0;i<(1<<bt);++i) h[i]=h[i]*1ll*h[i]%MOD;
		ntt(h,1<<bt,1);
		for(int i=0,j=qp(1<<bt,MOD-2);i<(1<<bt);++i) h[i]=h[i]*1ll*j%MOD;
		ntt(h,1<<bt,0);
		for(int i=0;i<(1<<bt);++i) h[i]=h[i]*1ll*t[i]%MOD;
		ntt(h,1<<bt,1);
		for(int i=0,j=qp(1<<bt,MOD-2);i<(1<<bt);++i) h[i]=h[i]*1ll*j%MOD;
		for(int i=0;i<(1<<bt-1);++i) b[i]=(2*b[i]-h[i])%MOD,b[i]=(b[i]+MOD)%MOD;
	}
}
void Dfs(int nw){
	if(vis[nw]) return;
	vis[nw]=1;
	for(map<int,int>::iterator iter=e[nw].begin();iter!=e[nw].end();++iter)
		Dfs((*iter).first),ban[nw]|=ban[(*iter).first];
}
void dfs(int nw){
	if(vis[nw]) return;
	vis[nw]=1;
	for(map<int,int>::iterator iter=e[nw].begin();iter!=e[nw].end();++iter)
		ban[(*iter).first]|=ban[nw],dfs((*iter).first);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);init();f.resize(m+1);
	for(int i=1,c;i<=n;++i){
		scanf("%d",&c);
		for(int j=1;j<=c;++j) scanf("%d",&a[j]);
		for(int j=1;j<c;e[a[j]][a[j+1]]=1,++j)
			if((pre[a[j+1]]&&pre[a[j+1]]-a[j])||(nxt[a[j]]&&nxt[a[j]]-a[j+1])) ban[a[j]]=ban[a[j+1]]=1;
			else nxt[pre[a[j+1]]=a[j]]=a[j+1];
	}
	for(int i=1;i<=K;++i) Dfs(i);
	for(int i=1;i<=K;++i) vis[i]=0;
	for(int i=1;i<=K;++i) dfs(i);
	for(int i=1,l,j;i<=K;++i) if(!pre[i]&&!ban[i]){
		for(l=0,j=i;j;j=nxt[j]) ++l;
		++f[l];
	}
	f[0]=1;
	for(int i=1;i<=m;++i) f[i]=fix(-f[i]);
	Inv(f,m+1,g);
	printf("%d",g[m]);
	return 0;
}