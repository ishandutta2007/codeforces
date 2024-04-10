#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,op,x;
int main(){
	scanf("%d%d%d%d",&n,&k,&m,&t);
	while(t--){
		scanf("%d%d",&op,&x);
		if(op){
			n++;
			if(x<=k)k++;
		}
		else{
			if(x<k)n-=x,k-=x;
			else n=x;
		}
		printf("%d %d\n",n,k);
	}
	return 0;
}