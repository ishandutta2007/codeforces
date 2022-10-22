#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int n,q,ans[MAXN];
struct quest
{
	int lx,rx,ly,ry,h,id;
	bool operator <(const quest &Z)const {return h<Z.h;}
}Q[MAXN];

int siz;
struct data
{
	int x,y,id;
}mem[MAXN];

int root,pcnt;
struct kd_tree
{
	int x,y,id,l,r,minid,fa;
	int lx,rx,ly,ry;
}tree[MAXN];
#define ls(x) (tree[x].l)
#define rs(x) (tree[x].r)
int cmpx(data x,data y) {return x.x<y.x;}
int cmpy(data x,data y) {return x.y<y.y;}
void up(int x)
{
	if(tree[x].id==0x3f3f3f3f) tree[x].minid=-1;
	else tree[x].minid=x;

	if(tree[x].minid==-1) tree[x].minid=tree[ls(x)].minid;
	else if(tree[ls(x)].minid!=-1 && tree[tree[ls(x)].minid].id<tree[tree[x].minid].id) tree[x].minid=tree[ls(x)].minid;

	if(tree[x].minid==-1) tree[x].minid=tree[rs(x)].minid;
	else if(tree[rs(x)].minid!=-1 && tree[tree[rs(x)].minid].id<tree[tree[x].minid].id) tree[x].minid=tree[rs(x)].minid;
}
void build(int l,int r,int &x,int type)
{
	if(l>r) return;
	int mid=(l+r)>>1;
	x=++pcnt;
	nth_element(mem+l,mem+mid,mem+r+1,type?cmpx:cmpy);
	tree[x].x=tree[x].lx=tree[x].rx=mem[mid].x;
	tree[x].y=tree[x].ly=tree[x].ry=mem[mid].y;
	tree[x].id=mem[mid].id;
	build(l,mid-1,tree[x].l=0,type^1);
	build(mid+1,r,tree[x].r=0,type^1);
	if(ls(x))
	{
		tree[ls(x)].fa=x;
		tree[x].lx=min(tree[x].lx,tree[ls(x)].lx);
		tree[x].rx=max(tree[x].rx,tree[ls(x)].rx);
		tree[x].ly=min(tree[x].ly,tree[ls(x)].ly);
		tree[x].ry=max(tree[x].ry,tree[ls(x)].ry);
	}
	if(rs(x))
	{
		tree[rs(x)].fa=x;
		tree[x].lx=min(tree[x].lx,tree[rs(x)].lx);
		tree[x].rx=max(tree[x].rx,tree[rs(x)].rx);
		tree[x].ly=min(tree[x].ly,tree[rs(x)].ly);
		tree[x].ry=max(tree[x].ry,tree[rs(x)].ry);
	}
	up(x);
}
int apart(int lx,int rx,int ly,int ry,int x)
{
	if(tree[x].ry<ly) return 1;
	if(tree[x].ly>ry) return 1;
	if(tree[x].rx<lx) return 1;
	if(tree[x].lx>rx) return 1;
	return 0;
}
int contain(int lx,int rx,int ly,int ry,int x) {return lx<=tree[x].lx && tree[x].rx<=rx && ly<=tree[x].ly && tree[x].ry<=ry;}
void solve(int lx,int rx,int ly,int ry,int x,int &ANS)
{
	if(!x) return;
	if(apart(lx,rx,ly,ry,x)) return;
	if(contain(lx,rx,ly,ry,x))
	{
		if(ANS==-1) ANS=tree[x].minid;
		else if(tree[x].minid!=-1 && tree[tree[x].minid].id<tree[ANS].id) ANS=tree[x].minid;
		return;
	}
	if(tree[x].id!=0x3f3f3f3f && lx<=tree[x].x && tree[x].x<=rx && ly<=tree[x].y && tree[x].y<=ry && (ANS==-1 || tree[x].id<tree[ANS].id)) ANS=x;
	solve(lx,rx,ly,ry,ls(x),ANS);
	solve(lx,rx,ly,ry,rs(x),ANS);
}
void del(int x)
{
	tree[x].id=0x3f3f3f3f;
	while(x!=0)
	{
		up(x);
		x=tree[x].fa;
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		Q[i].lx=read();
		Q[i].rx=read();
		Q[i].ly=read();
		Q[i].ry=read();
		Q[i].h=read();
		Q[i].id=i;
	}
	sort(Q+1,Q+n+1);
	q=read();
	for(int i=1;i<=q;++i)
	{
		++siz;
		mem[siz].x=read(),mem[siz].y=read();
		mem[siz].id=i;
	}
	tree[0].minid=-1;
	build(1,siz,root,0);
	//for(int i=1;i<=siz;++i) cout<<tree[i].x<<" "<<tree[i].y<<" "<<tree[i].fa<<" "<<tree[i].id<<" "<<tree[i].minid<<endl;
	for(int i=1;i<=n;++i)
	{
		int ANS=-1;
		solve(Q[i].lx,Q[i].rx,Q[i].ly,Q[i].ry,root,ANS);
		if(ANS!=-1)
		{
			//cout<<ANS<<" "<<tree[ANS].id<<endl;
			ans[tree[ANS].id]=Q[i].id;
			del(ANS);
		}
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
//ore no turn,draw!