#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <utility>
#include <map>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
#define Mset(i,x) memset((i),(x),sizeof(i))
using namespace std;
typedef long long ll;
const int MX=600000;
int N;
char S[MX];

const int Base=131,P=1000000123,Q=1000000321;
struct StrHash
{
	ll a[MX],b[MX],g[MX],h[MX];
	void init(char* s,int l)
	{
		a[0]=1,b[0]=1;
		Fr(i,1,l)
		{
			a[i]=a[i-1]*Base%P;
			b[i]=b[i-1]*Base%Q;
			g[i]=(g[i-1]*Base+s[i])%P;
			h[i]=(h[i-1]*Base+s[i])%Q;
		}
	}
	ll operator()(int l,int r)
	{
		ll p=(g[r]-g[l-1]*a[r-l+1]%P+P)%P;
		ll q=(h[r]-h[l-1]*b[r-l+1]%Q+Q)%Q;
		return (p<<31)|q;
	}
}Hash;


struct Str{int l,r;}A_[MX],B_[MX],*A=A_,*B=B_;
int ac,bc;


const int Mod=2999999;
struct HashTable{ll k;int v,nx;}E[MX];
int H[Mod],ec;
int& Find(ll k)
{
	int x=k%Mod;
	Fe(i,x)if(E[i].k==k)return E[i].v;
	E[++ec].k=k,E[ec].v=0,E[ec].nx=H[x],H[x]=ec;
	return E[ec].v;
}
void Clear()
{
	Fr(i,1,ec)H[E[i].k%Mod]=0;
	ec=0;
}


inline void Add(int l,int r,int p)
{
//	printf("[%d,%d]<=[%d,%d]\n",l,r,A[p].l,A[p].r);
	if(!(1<=l&&r<=N))return;
	if(r>=A[p].l)return;
	if(B[bc].l==l&&B[bc].r==r)return;
	B[++bc].l=l,B[bc].r=r;
}

void Down()
{
	Clear();
	Fr(i,1,ac)
	{
		int l=A[i].l,r=A[i].r;
		ll h=Hash(l,r);
		int& p=Find(h);
		if(!p)p=i;
		else Add(l,r+1,p),Add(l-1,r,p);
	}
}



int Solve()
{
	Fl(i,N,1)A[++ac].l=i,A[ac].r=i;
	int ans=0;
	while(1)
	{
		if(!ac)return ans;
	//	Fl(i,ac,1)printf("[%d,%d]",A[i].l,A[i].r);putchar('\n');
		++ans;
		Down(),ac=bc,bc=0;
		swap(A,B);
	//	Fr(i,1,ac)A[i]=B[i];
	}
}


int main()
{
	scanf("%d%s",&N,S+1);
	Hash.init(S,N);
	int r=Solve();
	printf("%d\n",r);
	return 0;
}