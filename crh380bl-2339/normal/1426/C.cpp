#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n,y,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=(int)sqrt(1.0*n);
		if(x*x==n)printf("%d\n",x+x-2);
		else if(x*x+x>=n)printf("%d\n",x+x-1);
		else printf("%d\n",x+x);
	}
	return 0;
}