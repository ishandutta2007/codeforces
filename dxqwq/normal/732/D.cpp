// Problem: D. Exams
// Contest: Codeforces - Codeforces Round #377 (Div. 2)
// URL: https://codeforces.com/contest/732/problem/D
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
int a[1000003],b[1000003];
int f[1000003];
signed main()
{
	int m=read(),n=read();
	for(int i=1; i<=m; ++i) b[i]=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	int l=1,r=m,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		for(int i=1; i<=n; ++i) f[i]=-1;
		for(int i=1; i<=mid; ++i) f[b[i]]=max(f[b[i]],i);
		bool s=1;
		for(int i=1; i<=n; ++i) if(f[i]==-1) 
		{
			s=0;
			break;
		}
		for(int i=1,cur=0; i<=mid; ++i)
		{
			if(b[i]>0&&f[b[i]]==i) if(a[b[i]]>cur)
			{
				s=0;
				break;
			}
			else cur-=a[b[i]];
			else ++cur;
		}
		if(s) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
    return 0;
}