#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,A,B,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&A,&B);
		if(B>=3){
		puts("YES");
			printf("%lld %lld %lld\n",1LL*A,1LL*A*(B-1),1LL*A*B);
		}
		else if(B==1)puts("NO");
		else{
			puts("YES");
			printf("%lld %lld %lld\n",1LL*A,3LL*A,4LL*A);
		}
	} 
	return 0;
}