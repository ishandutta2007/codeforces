#include<bits/stdc++.h>
using namespace std;
int t,n,x,a,b;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&a,&b);
		x=a+b-n;
		printf("%d\n",max(a,b)-x+1);
	}
	return 0;
}