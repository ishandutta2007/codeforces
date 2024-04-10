#include<cstdio>
using namespace std;
const int o=1<<20;
int n,a[o],b[o],h[o],cnt,d[o],st[o],tp;bool vis[o];
struct Edge{int v,p,w;}e[o*2];
inline void ad(int U,int V,int W){++d[e[++cnt].v=V];e[cnt].p=h[U];e[h[U]=cnt].w=W;}
void dfs(int nw){
	int t;
	for(int&i=h[nw];i;i=e[i].p) if(!vis[(t=i)>>1])
		vis[i>>1]=1,dfs(e[i].v),st[++tp]=t^1;
}
inline bool init(int k){
	cnt=1;tp=0;
	for(int i=0;i<(1<<k);++i) d[i]=h[i]=0;
	for(int i=1,E=(1<<k)-1;i<=n;++i) ad(a[i]&E,b[i]&E,i),ad(b[i]&E,a[i]&E,i);
	for(int i=1;i<=cnt/2;++i) vis[i]=0;
	for(int i=0;i<(1<<k);++i) if(d[i]&1) return false;
	for(int i=0;i<(1<<k);++i) if(d[i]){dfs(i);break;}
	if(tp^n) return false;
	return true;
}
inline void print(){
	for(int i=1;i<=n;++i)
		if(st[i]&1) printf("%d %d ",2*e[st[i]].w,2*e[st[i]].w-1);
		else printf("%d %d ",2*e[st[i]].w-1,2*e[st[i]].w);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]);
	for(int k=1;k<=20;++k) if(!init(k)){init(k-1);printf("%d\n",k-1);print();return 0;}
	printf("20\n");print();
	return 0;
}