#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],blocks[1000003];
int n=read(),T=read()-n;
priority_queue<pair<int,int> >q;
int f(int x,int y)
{
	return (x/y)*(x/y)*(y-(x%y))+(x/y+1)*(x/y+1)*(x%y);
}
signed main()
{
	long long ans=0;
	for(int i=1; i<=n; i++) a[i]=read(),ans+=a[i]*a[i];
	for(int i=1; i<=n; i++)
	{
		blocks[i]=2;
		if(a[i]>1) q.push(mp(2ll*(a[i]-a[i]/2)*(a[i]/2),i));
	}
	while(T--)
	{
		int x=q.top().first,y=q.top().second;
		q.pop();
		ans-=x,++blocks[y];
		if(a[y]>=blocks[y]) q.push(mp(f(a[y],blocks[y]-1)-f(a[y],blocks[y]),y));
	}
	printf("%lld\n",ans);
}