#include<bits/stdc++.h>
const int N=2e5+3;
int n,a,b,x;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%d",&a);
	  b=x+a;
	  printf("%d ",b);
	  x=std::max(x,b);
	}
}