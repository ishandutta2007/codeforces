#include<cstdio>
#include<algorithm>
#include<cctype>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define G getchar()
ll read()
{
	ll x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
const ll INF=1e18;

ll n,K,w[400010]; int m;
pll bin[400010]; int bintop;
bool check1(ll x){
	ll res=0;
	for (int i=1;i<=m;i++) res+=w[i]/x;
	return res>=K+m;
}
bool check2(ll x){
	ll res=0;
	for(int i=1;i<=m;i++) res+=(w[i]+x-1)/x;
	return res<=K+m;
}
void init(){}
void solve(){
	n=read(),m=read(),K=read();
	w[0]=0; for (int i=1;i<=m;i++) w[i]=read(); w[++m]=n;
	for (int i=m;i;i--) w[i]-=w[i-1];
	ll L0,R0;
	ll l=1,r=n,mid;
	while (l<r){
		mid=l+r+1>>1;
		if (check1(mid)) l=mid;
		else r=mid-1;
	}
	L0=l;
	l=1,r=n;
	while (l<r){
		mid=l+r>>1;
		if (check2(mid)) r=mid;
		else l=mid+1;
	}
	R0=l;
	if (L0>=R0) return puts("0"),void();
	bintop=0;
	for (int i=1;i<=m;i++){
		ll a=(w[i]+R0-1)/R0,b=w[i]/L0;
		if (a<=b) continue;
		bin[++bintop]=(pll){w[i]/a,b?(w[i]+b-1)/b:INF};
	}
	bin[++bintop]=(pll){-INF,R0};
	bin[++bintop]=(pll){L0,INF};
	sort(bin+1,bin+bintop+1);
	ll ans=INF; ll premax=-INF;
	for (int i=1;i<bintop;i++){
		premax=max(premax,bin[i].nd);
		ans=min(ans,premax-bin[i+1].st);
	}
	printf("%I64d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}