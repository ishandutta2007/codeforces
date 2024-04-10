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

int main()
{
	//s s+1
	char s[10000]; //nw fh///dlqz
	scanf("%s",s+1);
	printf("%s",s+1);
	int l=strlen(s+1);
	for(int i=l ; i; --i)
	printf("%c",s[i]);
}//&