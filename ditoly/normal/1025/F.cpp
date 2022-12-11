#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MN 2000
struct P{int x,y;}p[MN+5],l[MN*MN/2+5];
int cnt,a[MN+5],b[MN+5];
inline P operator-(const P&a,const P&b){return (P){a.x-b.x,a.y-b.y};}
inline ll operator*(const P&a,const P&b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
bool cmp(const P&a,const P&b){return (p[a.y]-p[a.x])*(p[b.y]-p[b.x])<0;}
bool CMP(int x,int y){return p[x].x<p[y].x||(p[x].x==p[y].x&&p[x].y<p[y].y);}
ll cal(ll x){return x*(x-1)/2;}
int main()
{
	int n,i,j;ll ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y),a[i]=i;
	for(i=1;i<=n;++i)for(j=1;j<i;++j)
		l[++cnt]=CMP(i,j)?(P){i,j}:(P){j,i};
	sort(l+1,l+cnt+1,cmp);sort(a+1,a+n+1,CMP);
	for(i=1;i<=n;++i)b[a[i]]=i;
	for(i=1;i<=cnt;++i)
	{
		ans+=cal(b[l[i].x]-1)*cal(n-b[l[i].y]);
		swap(b[l[i].x],b[l[i].y]);
	}
	cout<<ans;
}