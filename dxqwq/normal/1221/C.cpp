// Problem: C. Perfect Team
// Contest: Codeforces - Educational Codeforces Round 73 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1221/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
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

signed main()
{
	for(int T=read();T--;)
	{
		int a=read(),b=read(),c=read();
		int l=1,r=min(a,b),ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int C=c;
			c+=(a-mid)+(b-mid);
			if(c>=mid)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
			c=C;
		}
		printf("%lld\n",ans);
	}
    return 0;
}