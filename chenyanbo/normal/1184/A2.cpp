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

#define N 270008

char s[N];
int r[N],rr[N],fl,o[N],n,f,ss,g;

int gcd(int a, int b) {
	if(!(a%b))return b;
	return gcd(b,a%b);
}

int main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)if(s[i]==49)++f;
	if(!(f%2))ss=1;
	if(!f)f=1; else f=0;
	for(int k=1;k<n;++k){
		g=gcd(n,k);
		if(g==1)f+=ss; else {
			if(r[g]){
				f+=rr[g];
				continue;
			}
			r[g]=1;
			memset(o,0,g*sizeof(int));
			fl=1;
			for(int i=1;i<=n;++i)if(s[i]==49)o[i%g]^=1;
			for(int i=0;i<g;++i)if(o[i]){
				fl=0;
				break;
			}
			f+=fl;
			rr[g]=fl;
		}
	}
	
	printf("%d",f);
	
}