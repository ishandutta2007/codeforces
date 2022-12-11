#include <iostream>
#include <cstdio>
using namespace std;
int n,a,b;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	int x=-1;
	for(int i=0,t=n/a;i<=t;++i)
		if((n-i*a)%b==0){x=i;break;}
	if(x==-1)puts("-1");
	else{
		for(int i=1;i<=x;++i)
			for(int j=1;j<=a;++j)
				printf("%d ",(i-1)*a+1+(j%a));
		int t=x*a;x=(n-x*a)/b;
		for(int i=1;i<=x;++i)
			for(int j=1;j<=b;++j)
				printf("%d ",t+(i-1)*b+1+(j%b));
		putchar(10);
	}
	return 0;
}