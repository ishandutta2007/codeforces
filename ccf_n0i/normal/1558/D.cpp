#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
const int mod=998244353;
int mypow(int x,int y){
	int z=1;while(y){if(y&1)z=1ll*z*x%mod;x=1ll*x*x%mod;y/=2;}return z;
}
int fac[600005],fiv[600005];
int cc(int x,int y){
	return 1ll*fac[x]*fiv[y]%mod*fiv[x-y]%mod;
}
int ans;
int rt,vl[200005],vr[200005],lc[200005],rc[200005],cnt;
int rnd[200005],sz[200005];
void pushup(int x){
	if(x)sz[x]=vr[x]-vl[x]+1;
	if(lc[x])sz[x]+=sz[lc[x]];
	if(rc[x])sz[x]+=sz[rc[x]];
}
int nwnd(int l,int r){
	cnt++;
	vl[cnt]=l;vr[cnt]=r;sz[cnt]=r-l+1;lc[cnt]=rc[cnt]=0;
	rnd[cnt]=((((1ll*rand())<<15)+rand())%2147483640);
	return cnt;
}
void split(int x,int y,int &l,int &r){
	if(!x){
		l=0;r=0;
		return;
	}
	if(sz[lc[x]]<y&&sz[lc[x]]+vr[x]-vl[x]+1>y){
		int t=y-sz[lc[x]]+vl[x];
		int tt=nwnd(t,vr[x]);
		vr[x]=t-1;
		l=x;r=tt;
		rc[tt]=rc[x];rc[x]=0;
		pushup(x);pushup(tt);
		return;
	}
	if(sz[lc[x]]>=y){
		r=x;split(lc[x],y,l,lc[x]);
		pushup(lc[x]);pushup(l);
	}
	else{
		l=x;split(rc[x],y-sz[lc[x]]-(vr[x]-vl[x]+1),rc[x],r);
		pushup(rc[x]);pushup(r);
	}
	pushup(x);
}
int merge(int x,int y){
	if(!x||!y) return x+y;
	if(rnd[x]>rnd[y]){
		rc[x]=merge(rc[x],y);
		pushup(x);
		return x;
	}
	else{
		lc[y]=merge(x,lc[y]);
		pushup(y);
		return y;
	}
}
int n,m,i,a[200005];
vector<int> seq;
void dfs(int x){
	ans+=vr[x]-vl[x];
	if(lc[x])dfs(lc[x]);
	seq.push_back(vl[x]);
	if(rc[x])dfs(rc[x]);
}
void solve(){
	rt=0;cnt=0;
	scanf("%d%d",&n,&m);
	int lst=1;
	rep(i,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if(lst<x){
			rt=merge(rt,nwnd(lst,x-1));
		}
		int l,r;
		split(rt,y-1,l,r);
		rt=merge(l,merge(nwnd(x,x),r));
		lst=x+1;
	}
	if(lst<=n){
		rt=merge(rt,nwnd(lst,n));
	}
	ans=0;
	seq.clear();dfs(rt);
	for(i=0;i+1<seq.size();i++){
		ans+=(seq[i]<seq[i+1]);
	}
	printf("%d\n",cc(n+ans,n));
}
int main(){
	srand(time(NULL));
	int i;
	fac[0]=1;
	rep(i,600000){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	fiv[600000]=mypow(fac[600000],mod-2);
	for(i=599999;i>=0;i--){
		fiv[i]=1ll*fiv[i+1]*(i+1)%mod;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}