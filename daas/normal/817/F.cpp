#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int m,n=1e18+1,root,pcnt,mem[100001][3],num[400010],cnt;
struct data
{
	signed tag,rev;
	int value;
}tree[1600010];
void build(int l,int r,int bj)
{
	tree[bj].tag=-1;
	if(l==r)
		return;
	int mid=(l+r)/2;
	build(l,mid,bj<<1);
	build(mid+1,r,bj<<1|1);
}
void down(int l,int r,int mid,int bj)
{
	if(tree[bj].tag!=-1)
	{
		if(tree[bj].tag)
		{
			tree[bj<<1].value=mid-l+1;
			tree[bj<<1|1].value=r-mid;
		}
		else
			tree[bj<<1].value=tree[bj<<1|1].value=0;
		tree[bj<<1].tag=tree[bj<<1|1].tag=tree[bj].tag;
		tree[bj<<1].rev=tree[bj<<1|1].rev=0;
		tree[bj].tag=-1;
	}
	if(tree[bj].rev)
	{
		tree[bj<<1].value=mid-l+1-tree[bj<<1].value;
		tree[bj<<1|1].value=r-mid-tree[bj<<1|1].value;
		if(tree[bj<<1].tag!=-1)
			tree[bj<<1].tag^=1;
		else
			tree[bj<<1].rev^=1;
		if(tree[bj<<1|1].tag!=-1)
			tree[bj<<1|1].tag^=1;
		else
			tree[bj<<1|1].rev^=1;
		tree[bj].rev=0;
	}
}
void xg(int l,int r,int L,int R,int type,int bj)
{
	if(L<=l && r<=R)
	{
		if(type==1)
			tree[bj].value=r-l+1,tree[bj].tag=1,tree[bj].rev=0;
		if(type==2)
			tree[bj].value=0,tree[bj].tag=0,tree[bj].rev=0;
		if(type==3)
		{
			tree[bj].value=r-l+1-tree[bj].value;
			if(tree[bj].tag!=-1)
				tree[bj].tag^=1;
			else
				tree[bj].rev^=1;
		}
		return;
	}
	int mid=(l+r)/2;
	down(l,r,mid,bj);
	if(L<=mid)
		xg(l,mid,L,R,type,bj<<1);
	if(mid<R)
		xg(mid+1,r,L,R,type,bj<<1|1);
	tree[bj].value=tree[bj<<1].value+tree[bj<<1|1].value;
}
int cx(int l,int r,int bj)
{
	//cout<<"cao "<<tree[bj].value<<" "<<l<<" "<<r<<endl;
	if(!tree[bj].value)
		return 0;
	if(l==r)
		return 1;
	int mid=(l+r)/2;
	down(l,r,mid,bj);
	if(tree[bj<<1].value==mid-l+1)
		return (mid-l+1)+cx(mid+1,r,bj<<1|1);
	else
		return cx(l,mid,bj<<1);
}
signed main()
{
	m=read();
	for(int i=1;i<=m;++i)
	{
		mem[i][0]=read();
		num[++cnt]=mem[i][1]=read();
		num[++cnt]=mem[i][2]=read();
	}
	num[++cnt]=1;
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	int fb=cnt;
	for(int i=2;i<=fb;++i)
		if(num[i]-1!=num[i-1])
			num[++cnt]=num[i]-1;
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	build(1,cnt,1);
	/*for(int i=1;i<=cnt;++i)
		cout<<num[i]<<" ";
	cout<<endl;*/
	for(int i=1;i<=m;++i)
	{
		int type=mem[i][0],l=lower_bound(num+1,num+cnt+1,mem[i][1])-num,r=lower_bound(num+1,num+cnt+1,mem[i][2])-num;
		xg(1,cnt,l,r,type,1);
		//cout<<l<<" "<<r<<" "<<type<<endl;
		printf("%lld\n",num[cx(1,cnt,1)]+1);
	}
	return 0;
}