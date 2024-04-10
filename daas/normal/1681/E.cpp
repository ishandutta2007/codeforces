#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,ins[MAXN][4],m;
struct matrix
{
	ll A[2][2];
	matrix operator *(const matrix &Z) const
	{
		matrix bck;
		memset(bck.A,0x3f,sizeof(bck.A));
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					bck.A[i][k]=min(bck.A[i][k],A[i][j]+Z.A[j][k]+1);
		return bck;
	}
}tree[MAXN*4];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
int calc(int ax,int ay,int bx,int by) {return abs(ax-bx)+abs(ay-by);}
void build(int l,int r,int x)
{
	if(l==r)
	{
		tree[x].A[0][0]=calc(ins[l-1][0]+1,ins[l-1][1],ins[l][0],ins[l][1]);
		tree[x].A[0][1]=calc(ins[l-1][0]+1,ins[l-1][1],ins[l][2],ins[l][3]);
		tree[x].A[1][0]=calc(ins[l-1][2],ins[l-1][3]+1,ins[l][0],ins[l][1]);
		tree[x].A[1][1]=calc(ins[l-1][2],ins[l-1][3]+1,ins[l][2],ins[l][3]);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
	tree[x]=tree[ls(x)]*tree[rs(x)];
}
matrix cx(int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R) return tree[x];
	int mid=(l+r)>>1;
	if(R<=mid) return cx(l,mid,L,R,ls(x));
	if(mid<L) return cx(mid+1,r,L,R,rs(x));
	return cx(l,mid,L,R,ls(x))*cx(mid+1,r,L,R,rs(x));
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		ins[i][0]=read(),ins[i][1]=read();
		ins[i][2]=read(),ins[i][3]=read();
	}
	build(1,n,1);
	m=read();
	while(m--)
	{
		int ax=read(),ay=read(),bx=read(),by=read();
		if(max(ax,ay)>max(bx,by)) swap(ax,bx),swap(ay,by);
		if(max(ax,ay)==max(bx,by)) {printf("%d\n",calc(ax,ay,bx,by));continue;}
		if(max(ax,ay)+1==max(bx,by))
		{
			int id=max(ax,ay);
			printf("%d\n",min(
				calc(ax,ay,ins[id][0],ins[id][1])+calc(bx,by,ins[id][0]+1,ins[id][1])
				,calc(ax,ay,ins[id][2],ins[id][3])+calc(bx,by,ins[id][2],ins[id][3]+1))+1);
			continue;
		}
		int id1=max(ax,ay),id2=max(bx,by);
		ll ans=0x3f3f3f3f3f3f3f3f;
		matrix V=cx(1,n,id1+1,id2-1,1);
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				ans=min(ans,calc(ax,ay,ins[id1][2*i],ins[id1][2*i+1])+calc(bx,by,ins[id2-1][2*j]+(j==0),ins[id2-1][2*j+1]+(j==1))+2+V.A[i][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
//ore no turn,draw!