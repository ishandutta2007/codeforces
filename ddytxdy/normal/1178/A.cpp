#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N],ans[N],m,sum,tot;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),tot+=a[i];
	ans[++m]=1;sum=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]*2<=a[1])ans[++m]=i,sum+=a[i];
	}
	if(sum*2<=tot)puts("0");
	else{
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	}
	return 0;
}