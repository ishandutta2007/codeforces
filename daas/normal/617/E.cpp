#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=1e5+10;
const int MAXV=3e6+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,K,base,a[MAXN],ton[MAXV];
long long ANS,ans[MAXN];
struct quest
{
	int l,r,id;
	bool operator <(const quest &Z)const {return (l-1)/base==(Z.l-1)/base?r<Z.r:l<Z.l;}
}Q[MAXN];
void add(int v)
{
	ANS+=ton[K^v];
	++ton[v];
}
void reduce(int v)
{
	--ton[v];
	ANS-=ton[K^v];
}
int main()
{
	n=read(),q=read(),K=read();
	base=sqrt(n);
	for(int i=1;i<=n;++i) a[i]=a[i-1]^read();
	for(int i=1;i<=q;++i)
	{
		Q[i].l=read()-1,Q[i].r=read();
		Q[i].id=i;
	}
	sort(Q+1,Q+q+1);
	int L=0,R=0;
	ton[0]=1;
	for(int i=1;i<=q;++i)
	{
		while(R<Q[i].r)
		{
			++R;
			add(a[R]);
		}
		while(L>Q[i].l)
		{
			--L;
			add(a[L]);
		}
		while(L<Q[i].l)
		{
			reduce(a[L]);
			++L;
		}
		while(R>Q[i].r)
		{
			reduce(a[R]);
			--R;
		}
		ans[Q[i].id]=ANS;
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	return 0;
}
//ore no turn,draw!