#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		if(n<=2)puts("1");
		else{
			n-=2;
			printf("%d\n",(n-1)/x+2);
		}
	}
	return 0;
}