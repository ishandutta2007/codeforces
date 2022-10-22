#include<bits/stdc++.h>
using namespace std;
int T,n,res;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),res=0;
		while(n>=10)res+=(n/10)*10,n=n%10+n/10;
		printf("%d\n",res+n);
	}
	return 0;
}