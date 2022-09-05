#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 3333;
int n,k,x[N],y[N],bh[N],num;Vi e[N];bool gg[N];
int s[N],len,ans[N],sz;bool ok;
void dfs(int dep, int lim){
	if(ok)return;
	if(dep>num){
		ok=1;sz=len;rep(i,1,len)ans[i]=s[i];return;
	}
	int deg=0;rep(i,0,SZ(e[dep])-1)deg+=!gg[e[dep][i]]&&!gg[dep];
	if(!deg){dfs(dep+1,lim);return;}
//	printf("dfs %d %d %d\n",dep,lim,deg);
	if(deg==1){
		if(lim>=1){
			int x=0;rep(i,0,SZ(e[dep])-1)if(!gg[e[dep][i]])x=e[dep][i];
			s[++len]=x;gg[x]=1;dfs(dep+1,lim-1);len--;gg[x]=0;
		}
		return;
	}
	if(lim>=1){s[++len]=dep;gg[dep]=1;dfs(dep+1,lim-1);len--;gg[dep]=0;}
	if(lim>=deg){
		Vi t;
		rep(i,0,SZ(e[dep])-1)if(!gg[e[dep][i]])s[++len]=e[dep][i],gg[e[dep][i]]=1,t.pb(e[dep][i]);
		dfs(dep+1,lim-deg);
		rep(i,0,SZ(t)-1)len--,gg[t[i]]=0;
	}
}
ll sqr(ll x){return x*x;}
bool ck(ll mid){
	rep(i,1,n)bh[i]=gg[i]=0,e[i].clear();
	rep(i,1,n)rep(j,i+1,n)if(sqr(x[i]-x[j])+sqr(y[i]-y[j])>mid)bh[i]=bh[j]=1;
	static int dy[N];
	num=0;rep(i,1,n)if(bh[i])bh[i]=++num,dy[num]=i;
	rep(i,1,n)rep(j,i+1,n)if(sqr(x[i]-x[j])+sqr(y[i]-y[j])>mid)
		e[bh[i]].pb(bh[j]),e[bh[j]].pb(bh[i]);
	ok=0;sz=len=0;dfs(1,k);if(!ok)return 0;
//	cerr<<num<<endl;
	static int a[N];rep(i,1,n)a[i]=0;rep(i,1,sz)a[dy[ans[i]]]=1;
	rep(i,1,n)if(!a[i]&&sz<k)sz++,a[i]=1;
	sz=0;rep(i,1,n)if(a[i])ans[++sz]=i;
	return 1;
}
int main() {
	read(n);read(k);rep(i,1,n)read(x[i]),read(y[i]);
//	rep(i,4,4)cerr<<ck(i)<<endl;return 0;
	
	ll l=0,r=2LL*32000*32000;
	while(l<r){
		ll mid=(l+r)>>1;
		if(ck(mid))r=mid;else l=mid+1;
	}
	cerr<<l<<endl;
	ck(l);
	rep(i,1,k)printf("%d ",ans[i]);
	return 0;
}