// Problem: C. Serval and Parenthesis Sequence
// Contest: Codeforces - Codeforces Round #551 (Div. 2)
// URL: https://codeforces.com/contest/1153/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003];
signed main()
{
	int n=read();
    scanf("%s",s+1);
    if(n&1)
    {
    	puts(":(");
    	return 0;
    }
    int cnt=0;
    for(int i=1; i<=n; i++) if(s[i]=='(') ++cnt;
	int m=n>>1;
	if(cnt>m)
	{
		puts(":(");
		return 0;
	}
	for(int i=1,x=0; i<=n; i++)
	{
		if(s[i]=='(') ++x;
		else if(s[i]==')') 
		{
			--x;
			if(x==0&&i!=n)
			{
				puts(":(");
				return 0;
			}
			if(x<0)
			{
				puts(":(");
				return 0;
			}
		}
		else if(cnt<m) s[i]='(',++cnt,++x;
		else  
		{
			s[i]=')';
			--x;
			if(x==0&&i!=n)
			{
				puts(":(");
				return 0;
			}
			if(x<0)
			{
				puts(":(");
				return 0;
			}
		}
	}
	for(int i=1; i<=n; i++) printf("%c",s[i]);
	puts("");
	return 0;
}