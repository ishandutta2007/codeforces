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
long long n,k,a,b,ss,p;
int main()
{
	n=read();
	k=read();
	a=read();
	b=read();
	if(k==1){
		cout<<(n-1)*a<<endl;
		exit(0);//return 0
	}
	while(n>1)
	{
		if(n<k){
			ss+=(n-1)*a;
			break;
		}
		if(!(n%k)){
			p=n/k;
			ss+=min((n-p)*a,b);
			n=p;
			continue;
		}
		p=n/k*k;
		ss+=(n-p)*a;
		n=p;
	}
	printf("%I64d\n",ss);
}