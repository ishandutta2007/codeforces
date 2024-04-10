#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=2e5;
int N,M;

struct Seg{int v,L,R;}T[MX<<6];
int cnt;
#define li T[i].L
#define ri T[i].R
void Open(int& x){if(!x)x=++cnt;}
void pushup(int i){T[i].v=T[li].v+T[ri].v;}
void Ins(int i,int x,int l,int r)
{
	if(l==r){++T[i].v;return;}
	int m=(l+r)>>1;
	if(x<=m)Open(li),Ins(li,x,l,m);
	else Open(ri),Ins(ri,x,m+1,r);
	pushup(i);
}

int Merge(int a,int b,int l,int r)
{
	if(!a||!b)return a|b;
	if(l==r){T[a].v+=T[b].v;return a;}
	int m=(l+r)>>1;
	T[a].L=Merge(T[a].L,T[b].L,l,m);
	T[a].R=Merge(T[a].R,T[b].R,m+1,r);
	pushup(a);
	return a;
}
void Merges(int& A,int& B,int a,int b,int l,int r)
{
	if(!B)return;
	if(a<=l&&r<=b){A=Merge(A,B,l,r),B=0;return;}
	Open(A);
	int m=(l+r)>>1;
	if(a<=m)Merges(T[A].L,T[B].L,a,b,l,m);
	if(b>m)Merges(T[A].R,T[B].R,a,b,m+1,r);
	pushup(A),pushup(B);
}

int Ans[MX];
int t[MX];
void GetAns(int i,int c,int l,int r)
{
	if(!T[i].v)return;
	if(l==r){Ans[l]=c;return;}
	int m=(l+r)>>1;
	GetAns(li,c,l,m);
	GetAns(ri,c,m+1,r);
}


int main()
{
//	freopen("ccf.in","r",stdin);
//	freopen("ccf.out","w",stdout);
	scanf("%d",&N);
	int l,r,x,y;
	Fr(i,1,N)
	{
		scanf("%d",&x);
		Open(t[x]),Ins(t[x],i,1,N);
	}
	scanf("%d",&M);
	Fr(j,1,M)
	{
		scanf("%d%d%d%d",&l,&r,&x,&y);
		if(x!=y)Merges(t[y],t[x],l,r,1,N);
	}
	
	Fr(i,1,100)GetAns(t[i],i,1,N);
	Fr(i,1,N)printf("%d ",Ans[i]);
	return 0;
}