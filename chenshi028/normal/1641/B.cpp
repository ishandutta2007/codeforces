#include<cstdio>
#include<map>
using namespace std;
const int o=510,O=1e6+10;
int T,n,a[o],b[o],bs,p[O],c[O],t[O],g,s;map<int,int> cnt;
inline void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),++cnt[a[i]];
	for(int i=1;i<=n;++i) if(cnt[a[i]]&1){printf("-1\n");return;}
	for(int N=0;n;n=N,N=0) for(int i=2;i<=n;++i) if(a[i]==a[1]){
		for(int j=2,k=i;j<i;++j,++k) p[++bs]=s+k,c[bs]=a[j];
		t[++g]=(i-1)*2;s+=t[g];
		for(int j=i-1;j>1;--j) b[++N]=a[j];
		for(int j=i+1;j<=n;++j) b[++N]=a[j];
		for(int j=1;j<=N;++j) a[j]=b[j];
		break;
	}
	printf("%d\n",bs);
	for(int i=1;i<=bs;++i) printf("%d %d\n",p[i],c[i]);
	printf("%d\n",g);
	for(int i=1;i<=g;++i) printf("%d ",t[i]);
	putchar('\n');
}
int main(){for(scanf("%d",&T);T--;cnt.clear(),bs=g=s=0) slv();return 0;}