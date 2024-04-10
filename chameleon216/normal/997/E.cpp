#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=240100;
int N,M,P[MX];

#define li (i<<1)
#define ri (i<<1|1)
struct SegmentTree{int v,z;}T[MX*4]; // max - min - len
inline void Put(int i,int x){T[i].v+=x,T[i].z+=x;}
inline void PushDown(int i){if(T[i].z)Put(li,T[i].z),Put(ri,T[i].z),T[i].z=0;}
void Add(int i,int l,int r,int a,int b,int x)
{
	if(a<=l&&r<=b){Put(i,x);return;}
	PushDown(i);
	int m=(l+r)>>1;
	if(a<=m)Add(li,l,m,a,b,x);
	if(b>m)Add(ri,m+1,r,a,b,x);
	T[i].v=min(T[li].v,T[ri].v);
}
int Search(int i,int l,int r)
{
	if(l==r)return l;
	PushDown(i);
	int m=(l+r)>>1;
	if(T[li].v==T[i].v)return Search(li,l,m);
	else return Search(ri,m+1,r);
}

struct Range{int u,d,l,r;}A[MX];
inline Range operator+(const Range& a,const Range& b)
{
	Range c;
	c.l=min(a.l,b.l),c.r=max(a.r,b.r);
	c.d=min(a.d,b.d),c.u=max(a.u,b.u);
	return c;
}
inline bool Check(const Range& a){return a.u-a.d==a.r-a.l;}
vector<int> C[MX];
int typ[MX],nc,O[MX],st1[MX],st2[MX];

void Build()
{
	int n=0,tp1=0,tp2=0;
	nc=N;
	Fr(i,1,N)
	{
		while(tp1&&P[i]>P[st1[tp1]])Add(1,1,N,st1[tp1-1]+1,st1[tp1],P[i]-P[st1[tp1]]),--tp1;
		while(tp2&&P[i]<P[st2[tp2]])Add(1,1,N,st2[tp2-1]+1,st2[tp2],P[st2[tp2]]-P[i]),--tp2;
		st1[++tp1]=i,st2[++tp2]=i,Add(1,1,N,1,i,-1);
		
		A[i].u=A[i].d=P[i],A[i].l=A[i].r=i,O[++n]=i;
		int s=Search(1,1,N);
		while(n>1&&A[O[n]].l!=s)
		{
			if(typ[O[n-1]]&&Check(A[C[O[n-1]].back()]+A[O[n]])) //
				C[O[n-1]].push_back(O[n]),A[O[n-1]]=A[O[n-1]]+A[O[n]],--n;
			else //
			{
				int x=++nc,l=n;
				A[x]=A[O[n]];
				do A[x]=A[x]+A[O[--l]];
				while(!Check(A[x]));
				Fr(j,l,n)C[x].push_back(O[j]);
				typ[x]=(n-l==1),n=l,O[n]=x;
			}
		}
	}
}

ll S[MX],Ss[MX],L[MX],R[MX];
int F[MX][17],D[MX],Ci[MX];
void dfs1(int x)
{
	int z=C[x].size();
	S[x]=typ[x]?(ll)z*(z-1)/2:1;
	ll s=0;
	Fr(i,0,z-1)
	{
		int y=C[x][i];
		dfs1(y),S[x]+=S[y],Ci[y]=i;
		s+=S[y],Ss[y]=s;
	}
	s=0;
	Fr(i,0,z-1)
	{
		int y=C[x][i];
		L[y]=s,s+=S[y];
		if(typ[x])s+=i;
	}
	s=0;
	Fl(i,z-1,0)
	{
		int y=C[x][i];
		R[y]=s,s+=S[y];
		if(typ[x])s+=z-i-1;
	}
}
void dfs2(int x,int f,int d)
{
	F[x][0]=f,D[x]=d;
	Fr(k,1,16)F[x][k]=F[F[x][k-1]][k-1];
	for(int y:C[x])L[y]+=L[x],R[y]+=R[x],dfs2(y,x,d+1);
}

ll Query(int l,int r)
{
//	printf("Query %d %d\n",l,r);
	--l,++r;
	int x=l,y=r;
	if(D[x]>D[y])
	{
		Fl(k,16,0)if(D[x]-D[y]>=(1<<k))
			x=F[x][k];
	}
	if(D[x]<D[y])
	{
		Fl(k,16,0)if(D[y]-D[x]>=(1<<k))
			y=F[y][k];
	}
	Fl(k,16,0)if(F[x][k]!=F[y][k])x=F[x][k],y=F[y][k];
	int z=F[x][0];
//	printf("LCA is %d\n",z);
	return R[l]-R[x]+L[r]-L[y]+Ss[y]-Ss[x]-S[y]
		+(typ[z]?(ll)(Ci[y]-Ci[x]-1)*(Ci[y]-Ci[x]-2)/2:0);
}

int main()
{
	scanf("%d",&N);
	N+=2,P[1]=N-1,P[N]=N;
	Fr(i,2,N-1)scanf("%d",&P[i]);
//	Fr(i,1,N)scanf("%d",&P[i]);
	
	Build();
	/*printf("%d\n",nc);
	Fr(x,1,nc)
	{
		printf("#%d: type=%d interval=[%d,%d] range=[%d,%d] ch={ ",x,typ[x],A[x].l,A[x].r,A[x].d,A[x].u);
		for(int y:C[x])printf("%d ",y);
		printf("} \n");
	}
	putchar('\n');*/
	dfs1(O[1]);
	dfs2(O[1],0,1);
	
	scanf("%d",&M);
	Fr(i,1,M)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",Query(l+1,r+1));
	}
	return 0;
}