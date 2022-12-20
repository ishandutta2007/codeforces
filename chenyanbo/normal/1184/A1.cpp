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

long long r,rr;

int main()
{
	scanf("%lld",&r);  --r;
	if(r>=4&&r%2==0){
		r-=2;
		printf("1 %lld\n",r/2);
		return 0;
	}
	if(r<4){
		puts("NO");return 0;
	}
	for(int i=2;i<=1000000;++i)if(!(r%i)){
		rr=r/i;
		rr-=i+1;
		if(rr>=2&&rr%2==0){
			printf("%d %lld\n",i,rr);
			return 0;
		}
	}
	puts("NO");
}