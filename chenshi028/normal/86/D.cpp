#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e6+10,B=400;
int n,a[o],q,c[o];long long res,ans[o];
struct Query{int l,r,id;}ask[o];
inline void ins(int x){res-=x*1ll*c[x]*c[x];++c[x];res+=x*1ll*c[x]*c[x];}
inline void del(int x){res-=x*1ll*c[x]*c[x];--c[x];res+=x*1ll*c[x]*c[x];}
inline bool cmp(Query x,Query y){if(x.l/B==y.l/B) return x.r<y.r;return x.l<y.l;}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=q;++i) scanf("%d%d",&ask[i].l,&ask[i].r),ask[i].id=i;
	sort(ask+1,ask+1+q,cmp);
	for(int i=ask[1].l;i<=ask[1].r;++i) ins(a[i]);
	ans[ask[1].id]=res;
	for(int i=1;i<q;ans[ask[++i].id]=res){
		for(int j=ask[i+1].l;j<ask[i].l;++j) ins(a[j]);
		for(int j=ask[i+1].r;j>ask[i].r;--j) ins(a[j]);
		for(int j=ask[i].l;j<ask[i+1].l;++j) del(a[j]);
		for(int j=ask[i].r;j>ask[i+1].r;--j) del(a[j]);
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	return 0;
}