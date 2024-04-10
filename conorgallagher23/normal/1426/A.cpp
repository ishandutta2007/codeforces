#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,x;
		scanf("%d%d",&n,&x);
		if(n<=2)puts("1");
		else{
			if((n-2)%x==0)printf("%d\n",(n-2)/x+1);
			else printf("%d\n",(n-2)/x+2);
		} 
	}
	return 0;
}