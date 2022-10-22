#include<cstdio>
using namespace std;
const int o=2e5+10;
int T,n;long long a[o];
inline void slv(){
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=n,flg=0;i;--i){
		if(a[i]+=a[i+1]) flg=1;
		if(flg&&i>1&&a[i]>=0){printf("No\n");return;}
		if(a[i]>0){printf("No\n");return;}
	}
	printf(a[1]?"No\n":"Yes\n");
}
int main(){
	for(scanf("%d",&T);T--;slv()) scanf("%d",&n),a[n+1]=0;
	return 0;
}