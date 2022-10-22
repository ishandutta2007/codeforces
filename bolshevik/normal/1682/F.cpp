#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10,MOD=1e9+7;
inline int lowbit(int x){return x&-x;}
int n,q,a[o],b[o],ans[o],s;long long psum[o],p[o];
struct FenwickTree{
	int b[o];
	inline void modify(long long pos,int val){
		for(long long l=1,r=n+2,md,v=pos;l<r;pos=l) if(p[md=l+r>>1]>=v) r=md;else l=md+1;
		for(;pos<=n+1;pos+=lowbit(pos)) b[pos]=(b[pos]+val)%MOD;
	}
	inline int query(long long pos){
		int res=0;
		for(long long l=0,r=n+1,md,v=pos;l<r;pos=l) if(p[md=(l+r>>1)+1]<=v) l=md;else r=md-1;
		for(;pos;pos-=lowbit(pos)) res=(res+b[pos])%MOD;return res;
	}
}T1,T2;
inline void slv(){
	for(int i=1;i<=n;++i) psum[i+1]=psum[i]+b[i],p[i]=psum[i];
	p[1]=0;p[n+1]=psum[n+1];sort(p+1,p+n+2);
	for(int i=n,v;i;--i){
		if(b[i]>0)
			s=(s-a[i]*1ll*b[i]%MOD+MOD)%MOD,T1.modify(psum[i],a[i]*1ll*b[i]%MOD),T1.modify(psum[i]+b[i],a[i]*1ll*b[i]%MOD),
			T1.modify(psum[i],v=MOD-((psum[i]%MOD+MOD)*2ll*a[i]+a[i]*1ll*b[i])%MOD),T1.modify(psum[i]+b[i],MOD-v),
			T2.modify(psum[i],v=2*a[i]%MOD),T2.modify(psum[i]+b[i],MOD-v);
		ans[i]=(T1.query(psum[i]-1)+(psum[i]%MOD+MOD)*T2.query(psum[i]-1)+s+ans[i])%MOD;
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	slv();
	for(int i=1;i<=n+1;++i) T1.b[i]=T2.b[i]=0;
	for(int i=1;i<=n;++i) b[i]=-b[i];
	s=0;slv();
	for(int l,r;q--;printf("%d\n",(ans[l]+MOD-ans[r+1])%MOD)) scanf("%d%d",&l,&r);
	return 0;
}