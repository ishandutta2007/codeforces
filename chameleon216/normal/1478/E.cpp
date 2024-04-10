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
const int MX=210000;
char S[MX];
int N,M,X[MX],Y[MX];
int L[MX],R[MX];

struct Seg
{
	int v,z,l,r;
	Seg *L,*R;
	void update(int x){v=x*(r-l+1),z=x;}
	void pushup(){v=L->v+R->v;}
	void pushdown(){if(z!=-1)L->update(z),R->update(z),z=-1;}
	void init(int a,int b);
	void assign(int a,int b,int x);
	int ask(int a,int b);
}T[MX<<1],*tcnt=T;
Seg* New(){return ++tcnt;}
void Seg::init(int a,int b)
{
	l=a,r=b,z=-1;
	if(l==r){v=Y[l];return;}
	int m=(l+r)>>1;
	L=New(),L->init(l,m),R=New(),R->init(m+1,r);
	pushup();
}
void Seg::assign(int a,int b,int x)
{
	if(a<=l&&r<=b){update(x);return;}
	pushdown();
	if(a<=L->r)L->assign(a,b,x);
	if(b>=R->l)R->assign(a,b,x);
	pushup();
}
int Seg::ask(int a,int b)
{
	if(a<=l&&r<=b)return v;
	pushdown(); int A=0;
	if(a<=L->r)A+=L->ask(a,b);
	if(b>=R->l)A+=R->ask(a,b);
	return A;
}

int mian()
{
	scanf("%d%d",&N,&M);
	scanf("%s",S+1);
	Fr(i,1,N)X[i]=S[i]-'0';
	scanf("%s",S+1);
	Fr(i,1,N)Y[i]=S[i]-'0';
	Fr(i,1,M)scanf("%d%d",L+i,R+i);
	T->init(1,N);
	Fl(i,M,1)
	{
		int l=L[i],r=R[i];
		int x=T->ask(l,r);
		if(x*2==r-l+1)return 0;
		else if(x*2<r-l+1)T->assign(l,r,0);
		else T->assign(l,r,1);
		//Fr(j,1,N)printf("%d",T->ask(j,j));
		//putchar('\n');
	}
	Fr(i,1,N)if(T->ask(i,i)!=X[i])return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)
	{
		int res=mian();
		if(res)printf("yeS\n");
		else printf("nO\n");
		tcnt=T;
	}
}