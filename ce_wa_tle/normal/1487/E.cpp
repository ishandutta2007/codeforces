#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...) (void)(0)
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
using std::max;
using std::min;
inline ll readll(void){
	ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
inline ll iabs(ll x){
	return max(x,-x);
}
//#define a=b a=0-b
//#define b y,
inline int readchar(void){
	int ch=getchar();
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
struct cmp{
	const ll*a;
	cmp(const ll*b):a(b){}
	operator()(ll x,ll y)const{return a[x]<a[y];}
};
const ll N=155555,M=222222<<1;
ll a[4][N],c[N],c_[N],f[N],g[N],l[N],n[3];
ll next[M],head[N],to[M],cnt=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
int main(int QwQcOrZ,char*Recall_902_[]){
//	IO(A);
	rep(j,0,3)n[j]=readll();
	rep(j,0,3)rep(i,1,n[j])a[j][i]=readll();
	rep(i,1,n[0])f[i]=a[0][i];
	rep(j,1,3){
		ll m=readll();
		rep(i,1,n[j-1])c[i]=i;
		std::sort(c+1,c+n[j-1]+1,cmp(f)),cnt=0;
		c[n[j-1]+1]=0;
		rep(i,1,n[j-1])c_[c[i]]=i;
		rep(i,1,n[j])head[i]=0;
		rep(i,1,m){
			ll u=readll(),v=readll();
			add(v,u);
		}
		f[0]=inf;
		rep(i,1,n[j]){
			ll now=1;
			rfor(ll k=head[i];k;k=next[k]){
				g[c_[to[k]]]++;
				while(g[now])now++;
			}
			l[i]=f[c[now]];
//			printf("%lld %lld %lld\n",j,i,c[now]);
			rfor(ll k=head[i];k;k=next[k]){
				g[c_[to[k]]]--;
			}
		}
		rep(i,1,n[j])f[i]=min(a[j][i]+l[i],inf);
	}
	ll mins=inf;
	rep(i,1,n[3])if(f[i]<mins)mins=f[i];
	printf("%lld\n",mins==inf?-1:mins);
	return 0;
}