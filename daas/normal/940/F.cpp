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
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,base,tim,change[MAXN][3],a[MAXN],mem[MAXN],Ton[MAXN*2],ton[MAXN],ans[MAXN],cnt,num[MAXN*2],tot;
struct quest
{
	int l,r,id,tim;
	bool operator <(const quest &Z) const {return (l-1)/base==(Z.l-1)/base?((r-1)/base==(Z.r-1)/base?tim<Z.tim:r<Z.r):l<Z.l;}
}Q[MAXN];
void add(int v)
{
	--ton[Ton[v]];
	++Ton[v];
	++ton[Ton[v]];
}
void reduce(int v)
{
	--ton[Ton[v]];
	--Ton[v];
	++ton[Ton[v]];
}
int main()
{
	n=read(),q=read();
	base=pow(n,2.0/3);
	for(int i=1;i<=n;++i) num[++tot]=mem[i]=a[i]=read();
	for(int i=1;i<=q;++i)
	{
		int type=read();
		if(type==1)
		{
			int l=read(),r=read();
			++cnt;
			Q[cnt].tim=tim;
			Q[cnt].l=l;
			Q[cnt].r=r;
			Q[cnt].id=cnt;
		}
		else
		{
			int x=read(),y=read();
			num[++tot]=y;
			++tim;
			change[tim][0]=x;
			change[tim][1]=mem[x];
			change[tim][2]=y;
			mem[x]=y;
		}
	}
	sort(num+1,num+tot+1);
	tot=unique(num+1,num+tot+1)-num-1;
	for(int i=1;i<=n;++i) a[i]=lower_bound(num+1,num+tot+1,a[i])-num;
	for(int i=1;i<=tim;++i)
	{
		change[i][1]=lower_bound(num+1,num+tot+1,change[i][1])-num;
		change[i][2]=lower_bound(num+1,num+tot+1,change[i][2])-num;
	}
	sort(Q+1,Q+cnt+1);
	int L=1,R=1,T=0;
	add(a[1]);
	for(int i=1;i<=cnt;++i)
	{
		while(T<Q[i].tim)
		{
			++T;
			if(L<=change[T][0] && change[T][0]<=R)
			{
				reduce(change[T][1]);
				add(change[T][2]);
			}
			a[change[T][0]]=change[T][2];

		}
		while(T>Q[i].tim)
		{
			if(L<=change[T][0] && change[T][0]<=R)
			{
				reduce(change[T][2]);
				add(change[T][1]);
			}
			a[change[T][0]]=change[T][1];
			--T;
		}
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
		int ANS=1;
		while(ton[ANS]) ++ANS;
		ans[Q[i].id]=ANS;
	}
	for(int i=1;i<=cnt;++i) printf("%d\n",ans[i]);
	return 0;
}
//ore no turn,draw!