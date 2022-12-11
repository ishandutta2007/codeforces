#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<set>
#include<map>
#define MN 200005
#define ll long long
using namespace std;
struct meg1{ll x,y; int pos;}a[MN],c[MN];
struct meg2
{
	ll val; int pos;
	friend bool operator<(const meg2& a,const meg2& b)
	{
		return a.val<b.val||a.val==b.val&&a.pos<b.pos;
	}
}b[MN];
set<meg2> st;
int n,m;
int ans[MN];

inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool cmp1(const meg1& a,const meg1& b) {return a.y<b.y||a.y==b.y&&a.x<b.x;}

int main()
{
	register int i,j;
	n=read(); m=read();
	for (i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	for (i=1;i<n;++i) c[i].x=a[i+1].x-a[i].y,c[i].y=a[i+1].y-a[i].x,c[i].pos=i;
	for (i=1;i<=m;++i) b[i].val=read(),b[i].pos=i,st.insert(b[i]);
	sort(c+1,c+n,cmp1);
	
	for (i=1;i<n;++i)
	{
		set<meg2>::iterator k;
		k=st.lower_bound((meg2){c[i].x,0});
		if (k==st.end()||(*k).val>c[i].y) return 0*printf("No");
		ans[c[i].pos]=(*k).pos;
		st.erase(k);
	}
	puts("Yes");
	for (i=1;i<n;++i) printf("%d ",ans[i]);
	return 0;
}