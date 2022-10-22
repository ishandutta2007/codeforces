#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n,a[o],b[o];
inline void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	b[n+1]=b[1];
	for(int i=1;i<=n;++i) if(a[i]>b[i]||(b[i]>a[i]&&b[i]>b[i+1]+1)){printf("NO\n");return;}
	printf("YES\n");
}
int main(){
	for(scanf("%d",&T);T--;slv());
	return 0;
}