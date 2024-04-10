// Problem: D2. Kirk and a Binary String (hard version)
// Contest: Codeforces - Codeforces Round #581 (Div. 2)
// URL: https://codeforces.com/contest/1204/problem/D2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
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
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int S=0;
	for(int i=n; i>=1; --i)
	{
		if(s[i]=='0') ++S;
		else --S;
		if(S<0)
		{
			++S;
			s[i]='0';
		}
	}
	printf("%s\n",s+1);
	return 0;
}