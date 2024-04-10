// Problem: D. Playoff Tournament
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003];
int ans[4000003];
void build(int l,int r,int t)
{int i=t;
	if(l==r) 
	{
		ans[i]=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,t<<1);
	build(mid+1,r,(t<<1)+1);
	if(s[t]=='1') ans[i]=ans[i<<1];
	else if(s[t]=='0') ans[i]=ans[(i<<1)+1];
	else ans[i]=(ans[i<<1]+ans[(i<<1)+1]);
	return ;
}
signed main()
{
	int n=1<<read();
	scanf("%s",s+1);
	reverse(s+1,s+n);
	for(int i=1; i<=n; ++i) ans[i]=1;
	build(1,n,1);
    for(int T=read();T--;)
    {
    	int x=n-read();
    	char c=getchar();
    	while(!isdigit(c)&&c!='?') c=getchar();
    	s[x]=c;
    	for(int i=x; i; i>>=1)
    	{
			if(s[i]=='1') ans[i]=ans[i<<1];
			else if(s[i]=='0') ans[i]=ans[(i<<1)+1];
			else ans[i]=(ans[i<<1]+ans[(i<<1)+1]);
    	}
    	printf("%d\n",ans[1]);
    }
	return 0;
}