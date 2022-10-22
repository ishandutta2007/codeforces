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
const int MX=1e5+100;

int N;
ll qk[MX],ql[MX],qr[MX];
ll X[MX<<2],Len;

struct Data{int l0,l1;};
Data operator+(Data a,Data b)
{
	Data c;
	c.l0=a.l0!=-1?a.l0:b.l0;
	c.l1=a.l1!=-1?a.l1:b.l1;
	return c;
}
struct Seg
{
	Data v;
	int l,r;
	bool z1,z0,zf;//z1-->z0-->zf
	Seg *L,*R;
	void u1(){v.l0=-1,v.l1=l,z1=1,z0=0,zf=0;}
	void u0(){v.l0=l,v.l1=-1,z0=1,zf=0;}
	void uf(){swap(v.l0,v.l1),zf^=1;}
	void pu(){v=L->v+R->v;}
	void pd()
	{
		if(z1)L->u1(),R->u1(),z1=0;
		if(z0)L->u0(),R->u0(),z0=0;
		if(zf)L->uf(),R->uf(),zf=0;
	}
	void init(int,int);
	void add(int,int);
	void del(int,int);
	void flip(int,int);
}T[MX<<3],*tcnt=T;
inline Seg* New(){return ++tcnt;}
void Seg::init(int a,int b)
{
	l=a,r=b,v.l0=l,v.l1=-1;
	if(a==b)return;
	int m=(a+b)>>1;
	L=New(),L->init(a,m);
	R=New(),R->init(m+1,b);
}
void Seg::add(int a,int b)
{
	if(a<=l&&r<=b){u1();return;}
	pd();
	if(a<=L->r)L->add(a,b);
	if(b>=R->l)R->add(a,b);
	pu();
}
void Seg::del(int a,int b)
{
	if(a<=l&&r<=b){u0();return;}
	pd();
	if(a<=L->r)L->del(a,b);
	if(b>=R->l)R->del(a,b);
	pu();
}
void Seg::flip(int a,int b)
{
	if(a<=l&&r<=b){uf();return;}
	pd();
	if(a<=L->r)L->flip(a,b);
	if(b>=R->l)R->flip(a,b);
	pu();
}


int main()
{
	scanf("%d",&N);
	X[++Len]=1;
	Fr(i,1,N)scanf("%lld%lld%lld",qk+i,ql+i,qr+i),X[++Len]=ql[i],X[++Len]=qr[i],X[++Len]=qr[i]+1;
	sort(X+1,X+1+Len);
	Len=unique(X+1,X+1+Len)-X-1;
	T->init(1,Len);
	Fr(i,1,N)
	{
		int l=lower_bound(X+1,X+1+Len,ql[i])-X;
		int r=lower_bound(X+1,X+1+Len,qr[i])-X;
		switch(qk[i])
		{
		case 1:T->add(l,r);break;
		case 2:T->del(l,r);break;
		case 3:T->flip(l,r);break;
		}
		printf("%lld\n",X[T->v.l0]);
	}
	return 0;
}