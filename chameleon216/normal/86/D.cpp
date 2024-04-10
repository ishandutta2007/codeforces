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
const int MX=1000100;
int N,M;
ll X[MX];

const int Blo=548;
struct Query{int l,r,id;}Q[MX];
int blo[MX];
ll Aq[MX];
bool operator<(const Query& a,const Query& b)
{
	if(blo[a.l]!=blo[b.l])return a.l<b.l;
	return (blo[a.l]&1)?a.r<b.r:a.r>b.r;
}

int cnt[MX];
ll As;
inline void Add(int i){As+=(2*(++cnt[X[i]])-1)*X[i];}
inline void Del(int i){As-=(2*(cnt[X[i]]--)-1)*X[i];}

void MoQueue()
{
	Fr(i,1,N)blo[i]=(i-1)/Blo+1;
	sort(Q+1,Q+M+1);
	int l=1,r=0;
	Fr(i,1,M)
	{
		while(Q[i].l<l)Add(--l);
		while(Q[i].r>r)Add(++r);
		while(Q[i].l>l)Del(l++);
		while(Q[i].r<r)Del(r--);
		Aq[Q[i].id]=As;
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%lld",&X[i]);
	Fr(i,1,M)scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
	MoQueue();
	Fr(i,1,M)printf("%lld\n",Aq[i]);
	return 0;
}