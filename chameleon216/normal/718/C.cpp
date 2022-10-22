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
const int MX=1e5+100,Mod=1e9+7;
int N,M;
struct Mat
{
	ll v[2][2];
	Mat(){Fill(v,0);}
}Fib,Iden;
Mat operator+(const Mat& a,const Mat& b)
{
	Mat c;
	c.v[0][0]=(a.v[0][0]+b.v[0][0])%Mod;
	c.v[0][1]=(a.v[0][1]+b.v[0][1])%Mod;
	c.v[1][0]=(a.v[1][0]+b.v[1][0])%Mod;
	c.v[1][1]=(a.v[1][1]+b.v[1][1])%Mod;
	return c;
}
Mat operator*(const Mat& a,const Mat& b)
{
	Mat c;
	c.v[0][0]=(a.v[0][0]*b.v[0][0]+a.v[0][1]*b.v[1][0])%Mod;
	c.v[0][1]=(a.v[0][0]*b.v[0][1]+a.v[0][1]*b.v[1][1])%Mod;
	c.v[1][0]=(a.v[1][0]*b.v[0][0]+a.v[1][1]*b.v[1][0])%Mod;
	c.v[1][1]=(a.v[1][0]*b.v[0][1]+a.v[1][1]*b.v[1][1])%Mod;
	return c;
}
Mat operator^(Mat a,ll p)
{
	Mat r=Iden;
	while(p)
	{
		if(p&1)r=r*a;
		a=a*a,p>>=1;
	}
	return r;
}



struct Seg // 
{
	Mat v,z; //w^k(w)k 
	bool bz; // 
	int l,r;
	Seg *L,*R;
	void update(const Mat& x){v=v*x,z=z*x,bz=1;}
	void pushup(){v=L->v+R->v;}
	void pushdown(){if(bz)L->update(z),R->update(z),bz=0,z=Iden;} // 
	void init(int a,int b);
	void mul(int a,int b,const Mat& x);
	int ask(int a,int b);
}T[MX<<1],*cnt=T;
Seg* New(){return ++cnt;}
void Seg::init(int a,int b)
{
	l=a,r=b,z=Iden;
	if(l==r)
	{
		int x;
		scanf("%d",&x),v=Fib^x;
		return;
	}
	int m=(l+r)>>1;
	L=New(),L->init(l,m);
	R=New(),R->init(m+1,r);
	pushup();
}
void Seg::mul(int a,int b,const Mat& x)
{
	if(a<=l&&r<=b){update(x);return;}
	pushdown();
	if(a<=L->r)L->mul(a,b,x);
	if(b>=R->l)R->mul(a,b,x);
	pushup();
}
int Seg::ask(int a,int b)
{
	if(a<=l&&r<=b)return v.v[0][1];
	pushdown();
	int A=0;
	if(a<=L->r)A+=L->ask(a,b);
	if(b>=R->l)A+=R->ask(a,b);
	return A%Mod;
}


int main()
{
	Fib.v[0][0]=Fib.v[0][1]=Fib.v[1][0]=1;
	Iden.v[0][0]=Iden.v[1][1]=1;
	
	scanf("%d%d",&N,&M);
	T->init(1,N);
	int op,l,r;ll x;
	Fr(i,1,M)
	{
		scanf("%d%d%d",&op,&l,&r);
		switch(op)
		{
		case 1:scanf("%lld",&x),T->mul(l,r,Fib^x);break;
		case 2:printf("%d\n",T->ask(l,r));break; 
		}
	}
	return 0;
}