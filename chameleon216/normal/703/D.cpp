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
#define Fq(i,r) for(int i=H[r];i;i=Q[i].nx)
using namespace std;
typedef long long ll;
const int MX=1e6+100;
int N,M,A[MX],S[MX];
int Xor(int l,int r){return S[r]^S[l-1];}

struct Query{int l,id,nx;}Q[MX];
int H[MX],qc;
void add(int id,int l,int r)
{
	Q[++qc].id=id,Q[qc].l=l,Q[qc].nx=H[r],H[r]=qc;
}
int ans[MX];

struct Bit
{
	int v[MX];
	int lowbit(int x){return x&-x;}
	void add(int i,int x)
	{
		while(i<=N)v[i]^=x,i+=lowbit(i);
	}
	int ask(int i)
	{
		int r=0;
		while(i)r^=v[i],i-=lowbit(i);
		return r;
	}
	int operator()(int l,int r)
	{
		return ask(r)^ask(l-1);
	}
}bit;
map<int,int> mp;
void solve()
{
	Fr(i,1,N)
	{
		int a=A[i];
		int& x=mp[a];
		if(x)bit.add(x,a);
		x=i;
		bit.add(x,a);
		//Fr(j,1,N)printf("%d ",bit(j,j));printf("\n");
		Fq(j,i)ans[Q[j].id]=bit(Q[j].l,i)^Xor(Q[j].l,i);
	}
}

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",A+i);
	Fr(i,1,N)S[i]=S[i-1]^A[i];
	scanf("%d",&M);
	int l,r;
	Fr(i,1,M)scanf("%d%d",&l,&r),add(i,l,r);
	solve();
	Fr(i,1,M)printf("%d\n",ans[i]);
	return 0;
}