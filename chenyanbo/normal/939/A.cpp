#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,f[6005];
int main()
{
	n=read();
	for(int i=1; i<=n; ++i)f[i]=read();//f+i//int *a//*& //chuandi??
	for(int i=1; i<=n; ++i)if(f[ f[ f[i] ] ]==i){
		printf("Yes\n"); //""  puts
		exit(0);//return 0
	}
	puts("No");
}