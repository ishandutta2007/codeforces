#include<bits/stdc++.h>
using namespace std;
void work(int n){
	assert(n%3==2);
	int k=n/3,i;
	for(i=1;i<=k+1;++i)printf("%d %d\n",i,k+2-i);
	for(i=k+2;i<=k+k+1;++i)printf("%d %d\n",i,n+1-i);
}
int main(){
	int n,T;
	T=1;
	while(T--){
		scanf("%d",&n);
		printf("%d\n",(n+n+1)/3);
		if(n%3==0){
			work(n-1);
			printf("%d %d\n",n,n);
		}
		else if(n%3==1)work(n+1);
		else work(n);
	}
	return 0;
}