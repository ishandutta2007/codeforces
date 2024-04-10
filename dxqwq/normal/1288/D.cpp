#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int p=1,q=1,n,m,a[1000003][8],b[1000003],c[1003],mx;

bool check(int x)
{
	for(int i=1; i<=n; i++) b[i]=0;
	for(int i=0; i<=mx; i++) c[i]=0;
	for(int i=1; i<=n; i++) for(int j=0; j<m; ++j) if(a[i][j]>=x) b[i]+=(1<<j);
	for(int i=1; i<=n; i++) 
	{
		c[b[i]]=i;
		for(int j=0; j<=mx; j++) if(c[j]&&((b[i]|j)==mx)) 
		{
			p=i,q=c[j];
			return 1;
		}
	}
	return 0;
}
signed main()
{
	n=read(),m=read(),mx=(1<<m)-1;
	for(int i=1; i<=n; i++) for(int j=0; j<m; ++j) a[i][j]=read();
	int l=1,r=1000000000,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1; else r=mid-1;
	}
	printf("%d %d\n",p,q);
	return 0;
}