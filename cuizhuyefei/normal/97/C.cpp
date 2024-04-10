#include<bits/stdc++.h>
using namespace std;
int n;double p[123];
int main(){
	scanf("%d",&n);for(int i=0;i<=n;i++)scanf("%lf",&p[i]);
	double res=0;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){
		double a=n/2.0-i,b=n/2.0-j;if(a*b>=-1e-7)continue;
		a=a>0?a:-a;b=b>0?b:-b;res=max(res,(b*p[i]+a*p[j])/(a+b));
	}
	if(n%2==0)res=max(res,p[n/2]);
	printf("%.9lf",res);return 0;
}