#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
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
		for(x=0;!isdigit(c);c=Get())l=c;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	void GetS(char* s)
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
	void Write(Tp x)
	{
		if(x<0)Put('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)Put(stk[t--]);
	}
}IO;

const int MX=100100,Blo=300;
int N,M,I[MX];
string S[MX];
char tmp[MX];

int C[MX][26],F[MX],ac=1;
int Ins(string& s)
{
	int x=1;
	for(int c:s)
	{
		int k=c-'a';
		if(!C[x][k])C[x][k]=++ac;
		x=C[x][k];
	}
	return x;
}
void Build()
{
	queue<int> q;
	q.push(1);
	Fr(k,0,25)C[0][k]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		Fr(k,0,25)
		{
			if(C[x][k])F[C[x][k]]=C[F[x]][k],q.push(C[x][k]);
			else C[x][k]=C[F[x]][k];
		}
	}
}

vector<int> G[MX];
int sz[MX],dfn[MX],dfn_[MX],dc,V[MX];
ll sum[MX];
void dfs1(int x)
{
	sz[x]=1,dfn[x]=++dc,dfn_[dc]=x;
	for(int y:G[x])dfs1(y),sz[x]+=sz[y];
}

/*
struct Fenwick
{
	int v[MX];
	void Add_(int i,int x)
	{
		while(i<=ac)v[i]+=x,i+=i&-i;
	}
	void Add(int l,int r,int x)
	{
		Add_(l,x),Add_(r+1,-x);
	}
	int Ask(int i)
	{
		int r=0;
		while(i)r+=v[i],i-=i&-i;
		return r;
	}
}T;
*/
const int Num=MX/Blo+10;
int blo[MX],L[Num],R[Num];
int A[MX],B[Num];
void Init()
{
	Fr(i,1,ac)blo[i]=(i-1)/Blo+1;
	Fr(o,1,blo[ac])L[o]=(o-1)*Blo+1,R[o]=min(o*Blo,ac);
}
void Add(int l,int r)
{
	int a=blo[l],b=blo[r];
	if(a==b)Fr(i,l,r)++A[i];
	else
	{
		Fr(i,l,R[a])++A[i];
		Fr(i,L[b],r)++A[i];
		Fr(o,a+1,b-1)++B[o];
	}
}
int Ask(int i){return A[i]+B[blo[i]];}


struct Query
{
	int a,b,id;
	Query(){}
	Query(int a_,int b_,int id_){a=a_,b=b_,id=id_;}
};
vector<Query> Qb[MX],Qs[MX];
ll ans[MX];

void Big()
{
	Fr(i,1,N)if(Qb[i].size())
	{
		int x=1;
		for(char c:S[i])x=C[x][c-'a'],++V[x];
		Fl(j,ac,2)V[F[dfn_[j]]]+=V[dfn_[j]];
		Fr(j,1,N)sum[j]=sum[j-1]+V[I[j]];
		memset(V,0,(ac+1)*sizeof(int));
		for(Query& q:Qb[i])ans[q.id]+=sum[q.b]-sum[q.a-1];
	}
}

void Small()
{
	Fr(i,1,N)
	{
		Add(dfn[I[i]],dfn[I[i]]+sz[I[i]]-1);
		for(Query& q:Qs[i])
		{
			int x=1;
			for(char c:S[q.a])
			{
				x=C[x][c-'a'];
				ans[q.id]+=q.b*Ask(dfn[x]);
			}
		}
	}
}

int main()
{
	IO.Read(N),IO.Read(M);
	Fr(i,1,N)IO.GetS(tmp),S[i]=tmp;
	Fr(i,1,M)
	{
		int l,r,k;
		IO.Read(l),IO.Read(r),IO.Read(k);
		if((int)S[k].size()>=Blo)Qb[k].push_back(Query(l,r,i));
		else Qs[l-1].push_back(Query(k,-1,i)),Qs[r].push_back(Query(k,1,i));
	}
	
	Fr(i,1,N)I[i]=Ins(S[i]);
	Build();
	Fr(i,2,ac)G[F[i]].push_back(i);
	dfs1(1);
	Init();
	Big();
	Small();
	Fr(i,1,M)IO.Write(ans[i]),IO.Put('\n');
	return 0;
}