#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	
	FastIO(){p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char gc()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	void rs(char* s)
	{
		do *s=gc();
		while(*s<=32);
		while(*s>32)*++s=gc();
		*s=0;
	}
	template<typename T>
	void rd(T& x)
	{
		char c=gc(),l=0;
		for(x=0;!isdigit(c);c=gc())l=c;
		for(;isdigit(c);c=gc())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void wc(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void wd(T x)
	{
		if(x<0)wc('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)wc(stk[t--]);
	}
}IO;

const int MX=200100;
int N,M;
char S[MX];

int C[MX][26],F[MX],len[MX],sc=1,las=1;
int I[MX],id[MX],cnt[MX];
void Extend(char c)
{
	int k=c-'a',x=las,y=++sc;
	len[y]=len[x]+1,las=y;
	while(x&&!C[x][k])C[x][k]=y,x=F[x];
	if(!x)F[y]=1;
	else
	{
		int z=C[x][k];
		if(len[z]==len[x]+1)F[y]=z;
		else
		{
			int w=++sc;
			memcpy(C[w],C[z],sizeof(C[0]));
			len[w]=len[x]+1,F[w]=F[z],F[y]=F[z]=w;
			while(C[x][k]==z)C[x][k]=w,x=F[x];
		}
	}
}

struct Segment{int l,r;}T[MX*20];
int tc;
void Ins(int &i,int l,int r,int a)
{
	if(!i)i=++tc;
	if(l==r)return;
	int m=(l+r)>>1;
	if(a<=m)Ins(T[i].l,l,m,a);
	else Ins(T[i].r,m+1,r,a);
}
bool Ask(int i,int l,int r,int a,int b)
{
	if(b<l||r<a||!i)return 0;
	if(a<=l&&r<=b)return 1;
	int m=(l+r)>>1;
	return Ask(T[i].l,l,m,a,b)||Ask(T[i].r,m+1,r,a,b);
}
int Merge(int x,int y,int l,int r)
{
	if(!x||!y)return x|y;
	if(l==r)return x;
	int i=++tc,m=(l+r)>>1;
	T[i].l=Merge(T[x].l,T[y].l,l,m);
	T[i].r=Merge(T[x].r,T[y].r,m+1,r);
	return i;
}

int X[MX];
void Query()
{
	int l,r;
	IO.rd(l),IO.rd(r),IO.rs(S+1);
	int n=strlen(S+1),xc=0;
	X[0]=1;
	Fr(i,1,n)
	{
		int x=C[X[i-1]][S[i]-'a'];
		if(Ask(I[x],1,N,l+i-1,r))X[++xc]=x;
		else break;
	}
	Fl(i,xc,0)
	{
		int x=X[i],c=(i==n?0:S[i+1]-'a'+1);
		Fr(k,c,25)
		{
			int y=C[x][k];
			if(Ask(I[y],1,N,l+i,r))
			{
				Fr(j,1,i)IO.wc(S[j]);
				IO.wc('a'+k),IO.wc('\n');
				return;
			}
		}
	}
	IO.wd(-1),IO.wc('\n');
}

int main()
{
	IO.rs(S+1),IO.rd(M);
	N=strlen(S+1);
	Fr(i,1,N)Extend(S[i]),Ins(I[las],1,N,i);
	
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,sc)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
	Fl(i,sc,2)
	{
		int x=id[i];
		I[F[x]]=Merge(I[F[x]],I[x],1,N);
	}
	
	Fr(i,1,M)Query();
	return 0;
}