#include<stdio.h>
#include<math.h>
long long d[100005],t[100005];
long long sum[100005];
long long min(long long a,long long b){
	return (a<b)?a:b;
}
int main(){
	int n,p,m;
	scanf("%d %d %d",&n,&p,&m);
	for (int i=1;i<=n;i++){
		scanf("%I64d %I64d",&d[i],&t[i]);
	}
	d[n+1]=m+1;
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(long long)t[i];
	}
	long long ans=0;
	for (int i=1;i<=n+1;i++){
		long long prv=sum[i-1]-1ll*d[i-1]*p;
		if (prv<0) ans+=d[i]-d[i-1];
		else{
			long long dif=d[i]-d[i-1];
			long long td=(prv)/p+1;
			td=min(td,dif);
			ans+=dif-td;
		}
	}
	printf("%I64d\n",ans);
}