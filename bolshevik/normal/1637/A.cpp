#include<cstdio>
using namespace std;
const int o=1e5;
int T,n,a[o];
inline void slv(){
	for(int i=1;i<n;++i) if(a[i]>a[i+1]){printf("YES\n");return;}
	printf("NO\n");
}
int main(){
	for(scanf("%d",&T);T--;slv()){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	}
	return 0;
}