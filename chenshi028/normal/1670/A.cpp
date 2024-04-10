#include<cstdio>
#include<cmath>
using namespace std;
const int o=1e5+10;
int T,n,a[o],cnt;
inline void slv(){
	cnt=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),cnt+=(a[i]<0);
	for(int i=1;i<=cnt;++i) a[i]=-abs(a[i]);
	for(int i=n;i>cnt;--i) a[i]=abs(a[i]);
	for(int i=1;i<n;++i) if(a[i]>a[i+1]){printf("NO\n");return;;}
	printf("YES\n");
}
int main(){
	for(scanf("%d",&T);T--;slv()) scanf("%d",&n);
	return 0;
}