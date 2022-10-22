#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,a[o];long long ans;bool flg;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d",&n);flg=1;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		if(n==3&&a[2]%2){ans=-1;continue;}
		for(int i=2;i<n;++i) flg&=(a[i]==1),ans+=(a[i]+1)/2;
		if(flg) ans=-1;
	}
	return 0;
}