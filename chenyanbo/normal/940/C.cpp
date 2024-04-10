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

char s[100008];
int h,n,a[100008],k,b[100008],m;

int main()
{
	n=read(); k=read();
	scanf("%s",s+1);
	for(int i=1; i<=n; ++i)b[i]=a[i]=s[i];//-96;
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	if(k>n){
		for(int i=1; i<=n;++i)printf("%c",a[i]);
		for(int i=n+1; i<=k; ++i)printf("%c",b[1]);
		return 0;
	}
	
	for(int i=k; i; --i)if(a[i]!=b[m]){
		h=i;
		break;
	}
	
	for(int i=1; i<h; ++i)printf("%c",a[i]);
	
	for(int i=1; i<=m; ++i)if(a[h]==b[i])
	{
		printf("%c",b[i+1]);
		for(int j=h+1; j<=k; ++j)printf("%c",b[1]);//i
		exit(0);
	}
}