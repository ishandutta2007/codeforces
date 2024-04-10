// Problem: C. Interesting Story
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/contest/1551/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
char s[500003];
int c[500003][5],tot[500003];
int a[500003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) 
		{
			scanf("%s",s+1);
			int m=strlen(s+1);
			c[i][0]=c[i][1]=c[i][2]=c[i][3]=c[i][4]=0;
			for(int j=1; j<=m; ++j) ++c[i][s[j]-'a'];
			tot[i]=m;
		}
		int ans=0;
		for(int i=0; i<5; ++i)
		{
			for(int j=1; j<=n; ++j) a[j]=c[j][i]*2-tot[j];
			sort(a+1,a+n+1);
			if(a[n]>0)
			{
				int sum=a[n],A=1;
				for(int i=n-1; i>=1; --i)
					if(sum+a[i]>0) ++A,sum+=a[i];
					else break;
				ans=max(ans,A);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}