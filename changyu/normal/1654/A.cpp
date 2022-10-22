#include<bits/stdc++.h>
int n,a[1003];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	printf("%d\n",a[n]+a[n-1]);
	}return 0;
}