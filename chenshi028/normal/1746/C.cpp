#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,a[o],p[o];
inline bool cmp(int A,int B){return a[A-1]-a[A]<a[B-1]-a[B];}
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),p[i]=i;
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;++i) printf("%d ",p[i]);
	}
	return 0;
}