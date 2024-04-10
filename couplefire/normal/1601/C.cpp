#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1000100;
int N,M,A[MX],B[MX];
int id[MX];

bool cmp(int i,int j){return A[i]!=A[j]?A[i]<A[j]:i<j;}

#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
struct SegmentTree{int v,w,n;}T[MX<<2];
void PushUp(int i)
{
	T[i].v=T[li].v+T[ri].v;
	T[i].w=T[li].w+T[ri].w;
	T[i].n=min(T[li].n+T[ri].w,T[li].v+T[ri].n);
}
void Assign(int i,int l,int r,int a,int v,int w)
{
	if(l==r)
	{
		T[i].v=v,T[i].w=w;
		T[i].n=min(T[i].v,T[i].w);
		return;
	}
	if(a<=mid)Assign(li,l,mid,a,v,w);
	else Assign(ri,mid+1,r,a,v,w);
	PushUp(i);
}


struct Fenwick
{
	int v[MX];
	void Add(int i,int x)
	{
		while(i<=N)v[i]+=x,i+=i&-i;
	}
	int Ask(int i)
	{
		int r=0;
		while(i)r+=v[i],i-=i&-i;
		return r;
	}
}U;


ll Solve()
{
	ll ans=0;
	
	Fl(i,N,1)
	{
		int j=id[i];
		ans+=U.Ask(j);
		U.Add(j,1);
	}
//	printf("%lld\n",ans);
	
	Fr(i,1,N)Assign(1,1,N,i,1,0);
	int p=1,q=1;
	Fr(i,1,M)
	{
		while(q<=N&&A[id[q]]<=B[i])Assign(1,1,N,id[q++],0,0);
		while(p<=N&&A[id[p]]<B[i])Assign(1,1,N,id[p++],0,1);
		int n=T[1].n;
//		printf("%d\n",n);
//		Print(1,1,N),putchar('\n');
		ans+=n;
	}
	return ans;
}


int mian()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",&A[i]),id[i]=i;
	Fr(i,1,M)scanf("%d",&B[i]);
	sort(B+1,B+M+1);
	sort(id+1,id+N+1,cmp);
	printf("%lld\n",Solve());
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
		memset(U.v,0,(N+2)*sizeof(int));
		memset(T,0,((N+2)*4)*sizeof(SegmentTree));
	}
}