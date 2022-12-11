#include <iostream>
#include <cstdio>
using namespace std;
#define LLINT long long
int nums[100010],n;LLINT f[100010][2],t;
int main(){
	scanf("%d",&n);
	while(n--)scanf("%d",&t),++nums[t];
	for(int i=1;i<=100000;++i){
		f[i][0]=max(f[i-1][1],f[i-1][0]);
		f[i][1]=f[i-1][0]+1LL*nums[i]*i;
	}
	printf("%I64d\n",max(f[100000][0],f[100000][1]));
	return 0;
}