#include<cstdio>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
const int o=4e5+10;
int n,K,a[o],b[o],yny,whx,st[o],tp,sp,st2[o],tp2;long double ans=1e18,s;
inline bool chk(int i,int j,int k){return (b[j]-b[i])*1ll*(a[k]-a[i])==(b[k]-b[i])*1ll*(a[j]-a[i]);}
inline void slv(int x,int y){
	int t=0;
	for(int i=1;i<=n;++i) if(i-x&&i-y) t+=chk(x,y,i);
	if(t>=n-3) yny=x,whx=y;
}
inline bool cmp(int A,int B){return make_pair(a[A],b[A])<make_pair(a[B],b[B]);}
inline long double dis(int x,int y){return sqrtl((a[x]-a[y])*1ll*(a[x]-a[y])+(b[x]-b[y])*1ll*(b[x]-b[y]));}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]);
	slv(1,2);slv(1,3);slv(2,3);
	for(int i=1;i<=n;++i) if(i==yny||i==whx||chk(yny,whx,i)) st[++tp]=i;else sp=i;
	sort(st+1,st+tp+1,cmp);
	if(sp==K) ans=min(dis(K,st[1]),dis(K,st[tp]))+dis(st[1],st[tp]);
	else{
		for(int i=1;i<=tp;++i) if(st[i]==K){K=i;break;}
		for(int i=K;i;--i) st2[++tp2]=st[i];
		for(int i=K+1;i<=tp;++i) st2[++tp2]=st[i];
		for(int i=1;i<tp2;++i) s+=dis(st2[i],st2[i+1]);
		for(int i=1;i<tp2;++i) ans=min(ans,s-dis(st2[i],st2[i+1])+dis(st2[i],sp)+dis(st2[i+1],sp));
		ans=min(ans,s+dis(st2[tp2],sp));
		s=tp2=0;
		for(int i=K;i<=tp;++i) st2[++tp2]=st[i];
		for(int i=K-1;i;--i) st2[++tp2]=st[i];
		for(int i=1;i<tp2;++i) s+=dis(st2[i],st2[i+1]);
		for(int i=1;i<tp2;++i) ans=min(ans,s-dis(st2[i],st2[i+1])+dis(st2[i],sp)+dis(st2[i+1],sp));
		ans=min(ans,s+dis(st2[tp2],sp));
	}
	printf("%.8Lf",ans);
	return 0;
}