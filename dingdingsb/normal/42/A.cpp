#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
int n,v;
int a[10000+10],b[10000+10];
int sum=0;double ans=123456789;
signed main(){
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),ans=min(ans,1.0*b[i]/a[i]*sum);
	printf("%.5lf",min(ans,1.0*v));
}