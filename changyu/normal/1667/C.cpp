#include<bits/stdc++.h>
int n,m,k,k0,k1;
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("1\n1 1");
		return 0;
	}
	m=(n-2)/3*3+2;
	k=(n-2)/3*2+1;
	k0=k/2,k1=k-k0;
	printf("%d\n",k+n-m);
	for(int i=1;i<=k0;i++)printf("%d %d\n",i,k0+1-i);
	for(int i=1;i<=k1;i++)printf("%d %d\n",m-i+1,m-k1-1+i+1);
	for(int i=m+1;i<=n;i++)printf("%d %d\n",i,i);
	return 0;
}