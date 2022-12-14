#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
int n,a[300005],pre[300005],ans,A[1500005],B[1500005];
inline void add(re x,re y) {ans++;A[ans]=x,B[ans]=y;}
inline void s(re x,re y) {swap(a[x],a[y]);}
inline void solve(re x,re y)
{
	if(x>y) swap(x,y);
	if(y-x>=n/2) add(x,y),s(x,y);
	else
	{
		re l=1+(x==1),r=n-(y==n);
		if(x-1>=n/2&&y-1>=n/2)
		{
			add(x,1),add(1,y),add(1,x);
			s(x,y),swap(pre[a[x]],pre[a[y]]);
			return;
		}
		if(n-x>=n/2&&n-y>=n/2)
		{
			add(x,n),add(n,y),add(n,x);
			s(x,y),swap(pre[a[x]],pre[a[y]]);
			return;
		}
		add(x,r),add(r,l),add(l,y),add(l,r),add(r,x);
		s(x,r),s(r,l),s(l,y),s(l,r),s(r,x);
	}
	swap(pre[a[x]],pre[a[y]]);
}
int main()
{
	scanf("%d",&n);
	for(re i=1;i<=n;i++) scanf("%d",&a[i]),pre[a[i]]=i;
	if(n==2)
	{
		if(a[1]==1) puts("0");
		else puts("1\n1 2");
		return 0;
	}
	for(re i=1;i<=n;i++)
	if(a[i]!=i) solve(i,pre[i]);
	printf("%d\n",ans);
	for(re i=1;i<=ans;i++) printf("%d %d\n",A[i],B[i]);
	return 0;
}