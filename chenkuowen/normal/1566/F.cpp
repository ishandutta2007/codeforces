#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+2e5;
struct Inter{ ll l,r; };
vector<Inter> b[N];
ll a[N];
ll f[N][2];
void solve_left(vector<Inter> b,ll x,ll f[]){
	if(b.empty()) return;
	ll mir=1e9;
	for(auto x:b)
		mir=min(mir,x.r);
	f[0]+=(x-mir);
	f[1]+=2ll*(x-mir);
//	printf("[%lld]",x);
//	for(auto x:b) printf("<%lld %lld>",x.l,x.r); puts("");
//	printf("{%lld %lld}",f[0],f[1]);
}
void solve_right(vector<Inter> b,ll x,ll f[]){
	if(b.empty()) return;
	ll mxl=-1e9;
	for(auto x:b)
		mxl=max(mxl,x.l);
	f[0]+=2ll*(mxl-x);
	f[1]+=(mxl-x);
//	printf("[%lld]",x);
//	for(auto x:b) printf("<%lld %lld>",x.l,x.r); puts("");
//	printf("{%lld %lld}",f[0],f[1]);
}
bool cmp(Inter x,Inter y){ return x.l<y.l; }
void solve(vector<Inter> b,ll x,ll y,ll f[],ll g[]){
	g[0]=g[1]=(ll)2e18;
	b.push_back((Inter){x,x});
	b.push_back((Inter){y,y});
	sort(b.begin(),b.end(),cmp);
//	printf("[%lld %lld]",x,y);
//	for(auto t:b) printf("<%lld %lld>",t.l,t.r); puts("");
	multiset<ll> s;
	for(int i=0;i<b.size();++i) s.insert(b[i].r);
	for(int i=0;i+1<b.size();++i){
		s.erase(s.find(b[i].r));
		ll mxl=b[i].l;
		ll mir=*s.begin();
		ll k=min(f[0]+2ll*(mxl-x),f[1]+(mxl-x));
//		printf("/%lld %lld/",mxl,mir);
		g[0]=min(g[0],k+(y-mir));
		g[1]=min(g[1],k+2ll*(y-mir));
	}
//	printf("{%lld %lld}",g[0],g[1]);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		for(int i=0;i<=n+1;++i) b[i].clear();
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		sort(a+1,a+n+1); 
		for(int i=1;i<=m;++i){
			ll l,r; scanf("%lld%lld",&l,&r);
			int p=lower_bound(a+1,a+n+1,l)-a;
			if(p<=n&&a[p]<=r) continue;
			b[p-1].push_back((Inter){l,r});
		}
		f[1][0]=f[1][1]=0;
		solve_left(b[0],a[1],f[1]);
		for(int i=1;i<n;++i)
			solve(b[i],a[i],a[i+1],f[i],f[i+1]);
		solve_right(b[n],a[n],f[n]);
		printf("%lld\n",min(f[n][0],f[n][1]));
	}
	return 0;
}