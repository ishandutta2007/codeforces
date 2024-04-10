#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,k,s[o],a[o];
inline void slv(){
	scanf("%d%d",&n,&k);
	for(int i=n-k+1;i<=n;++i) scanf("%d",&s[i]);
	if(k==1){printf("Yes\n");return;}
	for(int i=n-k+2;i<=n;++i) a[i]=s[i]-s[i-1];
	for(int i=n-k+2;i<n;++i) if(a[i]>a[i+1]){printf("No\n");return;}
	if(a[n-k+2]*(n-k+1ll)<s[n-k+1]){printf("No\n");return;}
	printf("Yes\n");
}
int main(){
	for(scanf("%d",&T);T--;slv());
	return 0;
}