#include<bits/stdc++.h>
using namespace std;
#define MN 2000
typedef long long ll;
struct P{ll x,y;}p[MN+5],pp[MN*MN/2+5];
int cnt,a[MN+5],b[MN+5];
P operator-(P a,P b){return (P){a.x-b.x,a.y-b.y};}
ll operator*(P a,P b){return a.x*b.y-a.y*b.x;}
bool cmp(P a,P b){return (p[a.y]-p[a.x])*(p[b.y]-p[b.x])<0;}
bool cmpa(int x,int y){return p[x].x<p[y].x;}
ll cal(int x,int y){return (p[a[x]]-p[pp[y].x])*(p[pp[y].y]-p[pp[y].x]);}
void ans(int x,int y)
{
	puts("Yes");
	printf("%I64d %I64d\n",p[a[x]].x,p[a[x]].y);
	printf("%I64d %I64d\n",p[pp[y].x].x,p[pp[y].x].y);
	printf("%I64d %I64d\n",p[pp[y].y].x,p[pp[y].y].y);
	exit(0);
}
int main()
{
	ll n,s,i,j;
	cin>>n>>s;
	for(i=1;i<=n;++i)cin>>p[i].x>>p[i].y,a[i]=i;
	for(i=1;i<=n;++i)for(j=1;j<i;++j)
		pp[++cnt]=(p[i].x!=p[j].x?p[i].x<p[j].x:p[i].y<p[j].y)?(P){i,j}:(P){j,i};
	sort(pp+1,pp+cnt+1,cmp);
	sort(a+1,a+n+1,cmpa);
	for(i=1;i<=n;++i)b[a[i]]=i;
	for(i=1;i<=cnt;++i)
	{
		int l=1,r=n,mid;
		while(l<=r)
		{
			mid=l+r>>1;
			ll X=cal(mid,i);
			if(X==-s*2)ans(mid,i);
			if(X<-s*2)l=mid+1;else r=mid-1;
		}
		for(l=1,r=n;l<=r;)
		{
			mid=l+r>>1;
			ll X=cal(mid,i);
			if(X==s*2)ans(mid,i);
			if(X<s*2)l=mid+1;else r=mid-1;
		}
		swap(a[b[pp[i].x]],a[b[pp[i].y]]);
		swap(b[pp[i].x],b[pp[i].y]);
	}
	puts("No");
}