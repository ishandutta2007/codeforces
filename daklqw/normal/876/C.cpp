#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,digits[20],cnt,ks[20],ansl[2333],ansc;
bool pd(int x,int y){
	int t=x;
	while(t){
		x+=t%10;
		t/=10;
	}
	return x==y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2333;++i){
		if(n-i<0)break;
		if(pd(n-i,n))ansl[++ansc]=n-i;
	}
	printf("%d\n",ansc);
	for(int i=ansc;i;--i)
		printf("%d\n",ansl[i]);
	return 0;
}