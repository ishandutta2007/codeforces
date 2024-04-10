#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
char s[MN+5];
int z[MN+5],zn,cnt;
int main()
{
	int n,k,i;
	n=read();k=read();
	scanf("%s",s+1);
	for(i=1;i<=n;++i)
		if(s[i]=='(')z[++zn]=++cnt,cnt<=k/2?putchar('('):0;
		else z[zn]<=k/2?putchar(')'):0,--zn;
}