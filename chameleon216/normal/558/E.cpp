#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=120000;
int N,M;
char S[MX];

struct Data{int c[26];};
Data operator+(const Data& a,const Data& b)
{
	Data c;
	Fo(k,0,26)c.c[k]=a.c[k]+b.c[k];
	return c;
}

struct Seg
{
	Data d;
	int z,l,r;
	void ass(int x)
	{
		memset(d.c,0,sizeof(d.c));
		d.c[x]=r-l+1,z=x;
	}
}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
inline void pushup(int i){T[i].d=T[li].d+T[ri].d;}
inline void pushdown(int i)
{
	if(T[i].z!=-1)
	{
		T[li].ass(T[i].z);
		T[ri].ass(T[i].z);
		T[i].z=-1;
	}
}

void Build(int i,int l,int r)
{
	T[i].l=l,T[i].r=r,T[i].z=-1;
	if(l==r){T[i].d.c[S[l]-'a']=1;return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	pushup(i);
}

void Assign(int i,int a,int b,int x)
{
	if(a<=T[i].l&&T[i].r<=b)
		{T[i].ass(x);return;}
	pushdown(i);
	if(a<=T[li].r)Assign(li,a,b,x);
	if(b>=T[ri].l)Assign(ri,a,b,x);
	pushup(i);
}

Data Ask(int i,int a,int b)
{
	if(a<=T[i].l&&T[i].r<=b)
		return T[i].d;
	pushdown(i);
	if(b<=T[li].r)return Ask(li,a,b);
	if(a>=T[ri].l)return Ask(ri,a,b);
	return Ask(li,a,b)+Ask(ri,a,b);
}

void Print(int i)
{
	if(T[i].l==T[i].r)
	{
		Fo(k,0,26)if(T[i].d.c[k])
			{putchar(k+'a');break;}
		return;
	}
	pushdown(i);
	Print(li),Print(ri);
}


int main()
{
	scanf("%d%d%s",&N,&M,S+1);
	Build(1,1,N);
	Fr(i,1,M)
	{
		int l,r,o;
		scanf("%d%d%d",&l,&r,&o);
		Data d=Ask(1,l,r);
		int c[26];
		if(o)
		{
			c[0]=l;
			Fo(k,1,26)c[k]=c[k-1]+d.c[k-1];
			Fo(k,0,26)if(d.c[k])
				Assign(1,c[k],c[k]+d.c[k]-1,k);
		}
		else
		{
			c[25]=l;
			Fl(k,24,0)c[k]=c[k+1]+d.c[k+1];
			Fl(k,25,0)if(d.c[k])
				Assign(1,c[k],c[k]+d.c[k]-1,k);
		}
//		Print(1),putchar('\n');
	}
	Print(1),putchar('\n');
	return 0;
}