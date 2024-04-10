// Problem: D. Magazine Ad
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003];
signed main()
{
	int n=read(),m=0;
	int t=0;
	while(1)
	{
		char ch=getchar();
		if(ch=='\n'||ch==EOF) 
		{
			a[++m]=t;
			t=0;
			break;
		}
		else if(ch==' '||ch=='-')
		{
			a[++m]=t+1;
			t=0;
		}
		else ++t;
	}
	int l=1,r=100000000,ans=1000000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int s=0,k=1;
		for(int i=1; i<=m; i++) if(s+a[i]>mid)
		{
			if(a[i]>mid)
			{
				k=9999999;
				break;
			}
			++k;
			s=a[i];
		}
		else s+=a[i];
		//printf("%lld\n",k);
		if(k>n) l=mid+1;
		else ans=mid,r=mid-1;
	}
	printf("%lld\n",ans);
    return 0;
}