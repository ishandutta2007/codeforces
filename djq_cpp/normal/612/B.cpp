#include <cstdio>
int num[200005];
int abs(int n){
	return n>0?n:-n;
}
int main(){
	int n,p;
	long long ans=0;
	scanf("%d",&n);
	for(int k=1;k<=n;k++){
		scanf("%d",&p);
		num[p]=k;
	}
	for(int k=1;k<n;k++){
		ans+=(long long)abs(num[k]-num[k+1]);
	}
	printf("%I64d",ans);
	return 0;
}