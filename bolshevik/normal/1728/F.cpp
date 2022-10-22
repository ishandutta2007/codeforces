#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1010;
int n,a[o],st[o*o],tp,ptn[o],h[o*o],cnt;long long ans;bool vis[o*o];
struct Edge{int v,p;}e[o*o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
bool Hungary(int nw){
	for(int i=h[nw];i;i=e[i].p) if(!vis[e[i].v])
		if(!ptn[e[i].v]){ptn[e[i].v]=nw;return true;}
		else{vis[e[i].v]=1;if(Hungary(ptn[e[i].v])){ptn[e[i].v]=nw;return true;}}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1,j;i<=n;++i) for(scanf("%d",&a[i]),j=1;j<=n;++j) st[++tp]=a[i]*j;
	sort(st+1,st+tp+1);tp=unique(st+1,st+tp+1)-st-1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ad(lower_bound(st+1,st+tp+1,a[i]*j)-st,i);
	for(int i=1,j;i<=tp;++i) if(Hungary(i)) for(ans+=st[i],j=1;j<=tp;++j) vis[j]=0;
	printf("%lld",ans);
	return 0;
}