#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int T,n,a[o],b[o];
inline void slv(){
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n&1){printf("NO\n");return;}
	sort(a+1,a+n+1);
	for(int i=1,j=0;i<=n/2;++i) b[++j]=a[i],b[++j]=a[i+n/2];
	b[0]=b[n];b[n+1]=b[1];
	for(int i=1;i<=n;i+=2) if(!(b[i-1]>b[i]&&b[i]<b[i+1])){printf("NO\n");return;}
	for(int i=2;i<=n;i+=2) if(!(b[i-1]<b[i]&&b[i]>b[i+1])){printf("NO\n");return;}
	printf("YES\n");
	for(int i=1;i<=n;++i) printf("%d ",b[i]);
	putchar('\n');
}
int main(){
	for(scanf("%d",&T);T--;slv()) scanf("%d",&n);
	return 0;
}