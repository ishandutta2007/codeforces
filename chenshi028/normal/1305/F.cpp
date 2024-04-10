#include<cstdio>
#include<map>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) a=a*10+c-48;a*=f;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Min(int a,int b){return a<b?a:b;}
inline long long Max(long long a,long long b){return a>b?a:b;}
const int o=1e6+10;
int n,pri[o],cnt,ans,vis[o];long long mxa,a[o],seed=114514;map<long long,int> mp;
inline void linear_sieve(){
	int lim;
	for(lim=1;lim*1ll*lim<=mxa;++lim);
	for(int i=2;i<=lim;++i){
		if(!vis[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=lim;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}
inline int calc(long long p){
	if(mp[p]) return mp[p];
	long long res=0,t;
	for(int i=n;i;--i){
		if(a[i]<p) res+=p-a[i];
		else if((t=a[i]%p)*2<=p) res+=t;
		else res+=p-t;
		if(res>=ans) return mp[p]=n;
	}
	return mp[p]=res;
}
inline void slv(long long gc){
	if(gc<1) return;
	for(int i=1;i<=cnt&&pri[i]*1ll*pri[i]<=gc;++i) if(gc%pri[i]==0)
		for(ans=Min(ans,calc(pri[i]));gc%pri[i]==0;gc/=pri[i]);
	if(gc>1) ans=Min(ans,calc(gc));
}
int main(){
//	freopen("gcd.in","r",stdin);
//	freopen("gcd.out","w",stdout);
	read(n);ans=n;
	for(int i=1;i<=n;++i) read(a[i]),mxa=Max(a[i],mxa);
	linear_sieve();
	for(int i=1,j;i<=n&&i<=1000;++i) slv(a[j=(seed=seed*19260817%998244353)%n+1]-1),slv(a[j]),slv(a[j]+1);
	printf("%d",ans);
	return 0;
}