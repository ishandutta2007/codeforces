#include<cstdio>
using namespace std;
const int o=3e5+10;
int T,n,m,p[o],q[o],b[o],a[o],st[o],tp;bool vis[o];
inline bool chk(int k){
	if(a[k]<n-2*m) return false;
	for(int i=1;i<=n;++i) b[i]=q[(i-k+n-1)%n+1],vis[i]=0;
	int t=n;
	for(int i=1,j;i<=n;++i) if(!vis[i]) for(--t,j=i;!vis[j];j=b[j]) vis[j]=1;
	return t<=m;
}
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),tp=0){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) a[i]=0;
		for(int i=1;i<=n;++i) scanf("%d",&p[i]),++a[(i-p[i]+n)%n],q[p[i]]=i;
		for(int i=0;i<n;++i) if(chk(i)) st[++tp]=i;
		printf("%d ",tp);
		for(int i=1;i<=tp;++i) printf("%d ",st[i]);
	}
	return 0;
}