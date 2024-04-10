#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
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
	
	char Get()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void Read(Tp& x)
	{
		char c=Get(),l=0;
		for(x=0;!isdigit(c);c=Get())l=0;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	void ReadC(char& c)
	{
		do c=Get();
		while(c<=32);
	}
	void ReadS(char* s)
	{
		do *s=Get();
		while(*s<=32);
		while(*s>32)*++s=Get();
		*s=0;
	}
	
	void Put(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename Tp>
	void Write(Tp& x)
	{
		if(x<0)Put('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)Put(stk[t--]);
	}
	void Write(const char* s)
	{
		while(*s)Put(*s++);
	}
}IO;

const int MX=1100100;
char S[MX];
int N,M,qc;

int C[MX][26],F[MX],len[MX],I[MX],las=1,sc=1;
void Extend(char c)
{
	int k=c-'a',x=las,y=C[x][k]?MX-1:++sc;
	len[y]=len[x]+1;
	while(x&&!C[x][k])C[x][k]=y,x=F[x];
	if(!x)F[y]=1;
	else
	{
		int z=C[x][k];
		if(len[z]==len[x]+1)F[y]=z;
		else
		{
			int w=++sc;
			memcpy(C[w],C[z],sizeof(C[z]));
			len[w]=len[x]+1,F[w]=F[z],F[y]=F[z]=w;
			while(C[x][k]==z)C[x][k]=w,x=F[x];
		}
	}
	las=C[las][k];
}

int id[MX],cnt[MX],pre[MX],J[MX][21];
int Pos(int l,int r)
{
	int x=pre[r],n=r-l+1;
	Fl(i,20,0)if(len[J[x][i]]>=n)x=J[x][i];
	return x;
}

struct Query{int id,l,r;};
vector<Query> Q[MX];

struct Data{int x,p;}ans[MX];
inline Data operator+(Data a,Data b)
{
	return (a.x>b.x||(a.x==b.x&&a.p<b.p))?a:b;
}

struct Segment{Data v;int l,r;}T[50100*20];
int tc;
void Ins(int& i,int l,int r,int a)
{
	if(!i)i=++tc;
	if(l==r){++T[i].v.x,T[i].v.p=l;return;}
	int m=(l+r)>>1;
	if(a<=m)Ins(T[i].l,l,m,a);
	else Ins(T[i].r,m+1,r,a);
	T[i].v=T[T[i].l].v+T[T[i].r].v;
}
void Merge(int& x,int y,int l,int r)
{
	if(!x||!y){x|=y;return;}
	if(l==r){T[x].v.x+=T[y].v.x;return;}
	int m=(l+r)>>1;
	Merge(T[x].l,T[y].l,l,m);
	Merge(T[x].r,T[y].r,m+1,r);
	T[x].v=T[T[x].l].v+T[T[x].r].v;
}
Data Ask(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return T[i].v;
	int m=(l+r)>>1;
	if(b<=m)return Ask(T[i].l,l,m,a,b);
	if(a>m)return Ask(T[i].r,m+1,r,a,b);
	return Ask(T[i].l,l,m,a,b)+Ask(T[i].r,m+1,r,a,b);
}


int main()
{
	IO.ReadS(S+1),N=strlen(S+1);
	Fr(i,1,N)Extend(S[i]),pre[i]=las;
	
	IO.Read(M);
	Fr(i,1,M)
	{
		IO.ReadS(S+1);
		int n=strlen(S+1);
		las=1;
		Fr(j,1,n)Extend(S[j]),Ins(I[las],1,M,i);
	}
	
	/*int sum=0;
	Fr(i,1,sc)
	{
		Fr(k,0,25)sum+=C[i][k];
		sum+=F[i]+len[i];
	}
	printf("%d\n",sum);*/
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,sc)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
//	Fr(i,1,sc)printf("%d ",id[i]);putchar('\n');
	
	Fr(i,1,sc)
	{
		int x=id[i];
		J[x][0]=F[x];
		Fr(j,1,20)J[x][j]=J[J[x][j-1]][j-1];
	}
//	Fr(l,1,N)Fr(r,l,N)printf("[%d,%d]: %d\n",l,r,Pos(l,r));
	
	IO.Read(qc);
	Fr(i,1,qc)
	{
		int l,r;
		Query q;
		q.id=i,IO.Read(q.l),IO.Read(q.r),IO.Read(l),IO.Read(r);
		Q[Pos(l,r)].push_back(q);
	}
	
	Fl(i,sc,2)
	{
		int x=id[i];
//		printf("%d: %d %d\n",x,T[I[x]].v.p,T[I[x]].v.x);
		for(Query q:Q[x])
		{
			Data d=Ask(I[x],1,M,q.l,q.r);
			if(d.x==0)d.p=q.l;
			ans[q.id]=d;
		}
		Merge(I[F[x]],I[x],1,M);
	}
	Fr(i,1,qc)IO.Write(ans[i].p),IO.Put(' '),IO.Write(ans[i].x),IO.Put('\n');
	return 0;
}