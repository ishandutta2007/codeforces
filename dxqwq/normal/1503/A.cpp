// Problem: A. Balance the Bits
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[1000003];
char a[1000003],b[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	scanf("%s",s+1);
    	int ca=0,cb=0;
    	int A=0;
    	for(int i=1; i<=n; i++) if(s[i]=='0') ++A;
    	if(A&1)
    	{
    		puts("NO");
    		continue;
    	}
    	int t=(n-A)/2,g=0;
    	int p=0;
    	for(int i=1; i<=n; i++) if(s[i]=='1')
    	{
    		if(g<t)
    		{
    			a[i]=b[i]='(';
    			++g;
    		}
    		else a[i]=b[i]=')';
    	}
    	else
    	{++p;
    		if(p&1)
    		{
    			a[i]='(',b[i]=')';
    		}
    		else
    		{
    			a[i]=')',b[i]='(';
    		}
    	}
    	int s=0;
    	bool F=1;
    	for(int i=1; i<=n; i++) 
    	{
    		if(a[i]=='(') ++s;
    		else --s;
    		if(s<0) F=0;
    	}
    	for(int i=1; i<=n; i++) 
    	{
    		if(b[i]=='(') ++s;
    		else --s;
    		if(s<0) F=0;
    	}
    	if(F)
    	{
    		puts("YES");
    		for(int i=1; i<=n; i++) printf("%c",a[i]);
    		puts(""); 
    		for(int i=1; i<=n; i++) printf("%c",b[i]);
    		puts(""); 
    	}
    	else puts("NO");
    }
	return 0;
}