#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
int a[200001];
int n,p,k;
long long f[200001];
inline void Solve(){
	scanf("%d%d%d",&n,&p,&k);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(R i=1;i!=k;i++){
		f[i]=f[i-1]+a[i];
	}
	for(R i=k;i<=n;i++){
		f[i]=f[i-k]+a[i];
	}
	for(R i=1;i<=n;i++){
		if(f[i]<=p){
			ans=i;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}