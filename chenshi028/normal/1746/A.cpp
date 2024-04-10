#include<cstdio>
using namespace std;
int T,n,k,a[99];
inline void slv(){
	for(int i=1;i<=n;++i) if(a[i]==1){printf("YES\n");return;}
	printf("NO\n");
}
int main(){
	for(scanf("%d",&T);T--;slv()){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	}
	return 0;
}