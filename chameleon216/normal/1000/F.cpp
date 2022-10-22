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
#define Fq(i,x) for(int i=H[x];i;i=Q[i].nx)
using namespace std;
typedef long long ll;
const int MX=5e5+100;
int N,M,X[MX];

int Ans[MX];
struct Query{int id,l,nx;}Q[MX];
int H[MX],qc;
void add(int id,int l,int r)
{
	Q[++qc].id=id,Q[qc].l=l,Q[qc].nx=H[r],H[r]=qc;
}

int A[MX],B[MX];
int Del[MX]; // 

struct Seg
{
	int v,d; //  
	int l,r;
	Seg *L,*R;
	void update(int x,int e){if(e>=d)v=x,d=e;} // 
	void pushdown(){if(v!=-1)L->update(v,d),R->update(v,d),d=0,v=-1;}
	void init(int a,int b);
	void add(int a,int b,int x,int e);
//	void del(int a,int b,int e);
	int ask(int a);
}T[MX<<1],*cnt=T;
Seg* New(){return ++cnt;}
void Seg::init(int a,int b)
{
	l=a,r=b,v=-1;
	if(l==r){v=0;return;}
	int m=(l+r)>>1;
	L=New(),L->init(l,m);
	R=New(),R->init(m+1,r);
}
void Seg::add(int a,int b,int x,int e)
{
	if(a<=l&&r<=b){update(x,e);return;}
	pushdown();
	if(a<=L->r)L->add(a,b,x,e);
	if(b>=R->l)R->add(a,b,x,e);
}
int Seg::ask(int a)
{
	if(l==r)return v;
	pushdown();
	if(a<=L->r)return L->ask(a);
	else return R->ask(a);
}

// 000011110000
//    A   B

// 000000000000
//    A   B -1

// 000000001111
//        A   B +1

void solve()
{
	T->init(1,N);
	Fill(Del,0x7f);
	Fr(i,1,N)
	{
		int x=X[i];
	//	printf("[%d,%d] -1\n",A[x],B[x]);
		Del[B[x]]=i;
		A[x]=B[x]+1,B[x]=i;
	//	printf("[%d,%d] +1\n",A[x],B[x]);
	}
//	Fr(i,1,N)printf("%d ",Del[i]);printf("\n");
	Fill(A,0),Fill(B,0);
	Fr(i,1,N)
	{
		int x=X[i];
	//	if(A[x])printf("[%d,%d] -1(%d)\n",A[x],B[x],i);
		if(A[x])T->add(A[x],B[x],0,i);
		A[x]=B[x]+1,B[x]=i;
	//	printf("[%d,%d] +1(%d)\n",A[x],B[x],Del[i]);
		T->add(A[x],B[x],x,Del[i]);
	//	Fr(j,1,N)printf("%d ",T->ask(j));printf("\n");
		
		Fq(j,i)Ans[Q[j].id]=T->ask(Q[j].l);
	}
}



int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",X+i);
	scanf("%d",&M);
	int l,r;
	Fr(i,1,M)scanf("%d%d",&l,&r),add(i,l,r);
	solve();
	Fr(i,1,M)printf("%d\n",Ans[i]);
	return 0;
}