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
char s[5005],ss,n;
int main()
{
	n=read(); //s[0]  n n-1
	scanf("%s",s+1);
	if(n==1){
		cout<<s+1;
		return 0;
	}
	for(int i=1; i<=n; ++i)if(s[i]==48)++ss;
	printf("1");
	for(int i=1; i<=ss;++i)printf("0");
}