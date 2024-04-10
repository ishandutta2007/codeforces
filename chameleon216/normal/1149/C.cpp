#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=200100;

int N,M;
char S[MX];
int A[MX];

struct Segment
{
	int a,b,c,d,e;
	int z,l,r;
	Segment *L,*R;
	void add(int x){a+=x,b+=x,c-=x,d-=x,z+=x;}
	void PushUp()
	{
		a=max(L->a,R->a);
		b=min(L->b,R->b);
		c=max(max(L->c,R->c),L->a-2*R->b);
		d=max(max(L->d,R->d),R->a-2*L->b);
		e=max(max(L->e,R->e),max(L->c+R->a,L->a+R->d));
	}
	void PushDown(){if(z)L->add(z),R->add(z),z=0;}
	void Add(int a,int b,int x)
	{
		if(a<=l&&r<=b){add(x);return;}
		PushDown();
		if(a<=L->r)L->Add(a,b,x);
		if(b>=R->l)R->Add(a,b,x);
		PushUp();
	}
}T[MX<<1],*tc=T,*Tr;
void Build(Segment*& i,int l,int r)
{
	i=++tc,i->l=l,i->r=r;
	if(l==r){i->a=i->b=A[l],i->c=i->d=-A[l];return;}
	int m=(l+r)>>1;
	Build(i->L,l,m),Build(i->R,m+1,r);
	i->PushUp();
}


int main()
{
	int n;
	scanf("%d%d%s",&n,&M,S+1),N=strlen(S+1);
	Fr(i,1,N)A[i]=A[i-1]+(S[i]=='('?1:-1);
	Build(Tr,0,N);
	printf("%d\n",Tr->e);
	Fr(i,1,M)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l>r)swap(l,r);
		if(S[l]!=S[r])Tr->Add(l,r-1,S[l]=='('?-2:2),swap(S[l],S[r]);
		printf("%d\n",Tr->e);
	}
	return 0;
}