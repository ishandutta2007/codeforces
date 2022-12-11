#include<cstdio>
#define MN 1000
int n,a[MN+5],s,p0,p1;
int query(int l,int r)
{
	int i;
	printf("? ");
	for(i=1;i<l;++i)putchar('0');
	for(;i<=r;++i)putchar('1');
	for(;i<=n;++i)putchar('0');
	puts("");
	fflush(stdout);
	int x;scanf("%d",&x);
	return x;
}
void solve(int l,int r)
{
	if(p0&&p1)return;
	int mid=l+r>>1,i,x;
	x=query(l,mid);
	if(s+mid-l+1==x)p0=l,solve(mid+1,r);
	else if(s-mid+l-1==x)p1=l,solve(mid+1,r);
	else solve(l,mid);
}
int main()
{
	scanf("%d",&n);
	s=query(0,0);
	solve(1,n);
	printf("! %d %d",p0,p1);
	fflush(stdout);
}