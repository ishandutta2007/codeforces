#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <map>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fq(i,x) for(int i=H[x];i;i=Q[i].nx)
using namespace std;
typedef long long ll;
const int MX=5e5+100,INF=1e9;
int N,M,X[MX],cnt;
map<int,int> mp;

struct Seg
{
	int z;
	int l,r;
	Seg *L,*R;
	void update(int x){z=min(z,x);}
	void pushdown(){L->update(z),R->update(z);}
	void init(int a,int b);
	void Min(int a,int b,int x);
	int ask(int a);
}T[MX<<1],*Cnt=T;
Seg* New(){return ++Cnt;}
void Seg::init(int a,int b)
{
	l=a,r=b,z=INF;
	if(l==r)return;
	int m=(l+r)>>1;
	L=New(),L->init(l,m);
	R=New(),R->init(m+1,r);
}
void Seg::Min(int a,int b,int x)
{
	if(a<=l&&r<=b){update(x);return;}
	pushdown();
	if(a<=L->r)L->Min(a,b,x);
	if(b>=R->l)R->Min(a,b,x);
}
int Seg::ask(int a)
{
	if(l==r)return z;
	pushdown();
	if(a<=L->r)return L->ask(a);
	else return R->ask(a);
}

struct Query{int id,l,nx;}Q[MX];
int H[MX],qc;
void add(int id,int l,int r)
{
	Q[++qc].id=id,Q[qc].l=l,Q[qc].nx=H[r],H[r]=qc;
}
int ans[MX];


int A[MX];

void Solve()
{
	Fr(i,1,N)
	{
		int c=X[i];
		if(A[c])
		{
			int delta=i-A[c];
			T->Min(1,A[c],delta);
		}
		A[c]=i;
		Fq(j,i)ans[Q[j].id]=T->ask(Q[j].l);
	}
}


int main()
{
	scanf("%d%d",&N,&M);
	int x;
	Fr(i,1,N)
	{
		scanf("%d",&x);
		if(!mp.count(x))mp[x]=++cnt;
		X[i]=mp[x];
	}
	T->init(1,N);
	int l,r;
	Fr(i,1,M)
	{
		scanf("%d%d",&l,&r);
		add(i,l,r);
	}
	Solve();
	Fr(i,1,M)printf("%d\n",(ans[i]==INF?-1:ans[i]));
	return 0;
}