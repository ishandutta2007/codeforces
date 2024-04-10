// Problem: B2. Palindrome Game (hard version)
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/B2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
    for(int T=read();T--;)
    {
    		int n=read();
    	scanf("%s",s+1);
    	int ans=0;
    	for(int i=1; i<=n; ++i) if(s[i]=='0') ++ans;
    	if(n&1)
    	{
    		int N=(n+1)>>1;
    		if(s[N]=='0'&&ans!=1) puts("ALICE");
    		else
    		if(ans) puts("BOB");
    		else puts("DRAW");
    	}
    	else
    	{
    		if(ans) puts("BOB");
    		else puts("DRAW");
    	}
    	
    }
	return 0;
}