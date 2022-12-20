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
long long n;
int f[1009],t,ss;
int main()
{
	int t=read(); f[1]=0;
	for(int i=2;i<=1000; ++i){
		f[i]=10000;if(i%2==0)f[i]=min(f[i],f[i/2]+1);
		if(i%3==0)f[i]=min(f[i],f[i/3*2]+1);
		if(i%5==0)f[i]=min(f[i],f[i/5*4]+1);
	}
	while(t--){
		cin>>n;ss=0;
		while(n>1000){
			++ss;
			if(n%2==0)n=n/2;
			else if(n%3==0)n=n/3*2;
			else if(n%5==0)n=n/5*4;
			else goto lll;
		}
		if(f[n]==10000)goto lll;
		printf("%d\n",ss+f[n]);
		continue;
		lll:
		puts("-1");
		/*if(n%2&&n%3&&n%5){
			puts("-1");
			continue;
		}
		while(n%)*/
	}
}