#include<bits/stdc++.h>
int n,m;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	if(n%7==0){printf("%d\n",n);continue;}
	m=n-n%7;
	if(m/10==n/10){printf("%d\n",m);continue;}
	printf("%d\n",m+7);
	}return 0;
}