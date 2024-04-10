// Problem: B. World Cup
// Contest: Codeforces - Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// URL: https://codeforces.com/contest/931/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int b[1003];
int a[1003];
signed main()
{
	int G=0;
	int n=read(),aa=read()-1,bb=read()-1;
	while(1)
	{
		++G;
		n>>=1;
		aa>>=1,bb>>=1;
		if(n==1)
		{
			puts("Final!");
			return 0;
		}
		if(aa==bb)
		{
			printf("%d\n",G);
return 0;
		}
	}
    return 0;
}