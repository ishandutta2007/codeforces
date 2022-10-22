#include<cstdio>
using namespace std;
const int o=1010;
int m,k,a[o][o],sum1[o],v1;long long sum2[o],v2;
int main(){
	scanf("%d%d",&m,&k);
	for(int i=1;i<=k;++i) for(int j=1;j<=m;++j)
		scanf("%d",&a[i][j]),sum1[i]+=a[i][j],sum2[i]+=a[i][j]*1ll*a[i][j];
	for(int i=2;i<k;++i) if((sum1[i]-sum1[1])-(sum1[k]-sum1[1])/(k-1)*(i-1)){
		v1=(sum1[i-1]+sum1[i+1])/2;
		if(i>3) v2=sum2[1]+sum2[3]-2*sum2[2];
		else v2=sum2[k-2]+sum2[k]-2*sum2[k-1];
		v2=(sum2[i-1]+sum2[i+1]-v2)/2;
		v1-=sum1[i];v2-=sum2[i];
		printf("%d %lld",i-1,(v2-v1*v1)/(2*v1)+v1);
	}
	return 0;
}