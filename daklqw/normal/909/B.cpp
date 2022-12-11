#include <iostream>
#include <cstdio>
using namespace std;
int n,ans,f[110];
int main(){
	scanf("%d",&n);
	f[0]=0,f[1]=1,f[2]=2,f[3]=4,f[4]=6;
	for(int i=1;i<=100;++i)
		f[i+2]=f[i]+i+2;
	printf("%d\n",f[n]);
	return 0;
}