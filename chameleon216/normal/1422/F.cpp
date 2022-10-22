#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+10],*p,*q,c;
	char ob[MB+10],*r,stk[128];
	
	FastIO(){c=0,p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	void gc()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q){c=0;return;}
		}
		c=*p++;
	}
	template<typename T>
	void rd(T& x)
	{
		char l;
		for(l=0;!isdigit(c);gc())l=c;
		for(x=0;isdigit(c);gc())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void wc(char x)
	{
		if(r-ob==MB)fwrite(ob,1,MB,stdout),r=ob;
		*r++=x;
	}
	template<typename T>
	void wd(T x)
	{
		if(x<0)wc('-'),x=-x;
		int tp=0;
		do stk[++tp]=x%10+'0',x/=10;
		while(x);
		while(tp)wc(stk[tp--]);
	}
}IO;

const int MX=100100,Mod=1000000007;

const int W=200000;
char isp[W+100];
int P[MX],J[W+100],pc;
void Euler()
{
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0;
	Fr(i,2,W)
	{
		if(isp[i])P[++pc]=i,J[i]=pc;
		Fr(j,1,pc)
		{
			int p=P[j];
			if(i*p>W)break;
			isp[i*p]=0,J[i*p]=j;
			if(i%p==0)break;
		}
	}
}

int F[MX],cnt[MX],fc;
void Factor(int x)
{
	fc=0;
	while(x>1)
	{
		if(F[fc]!=J[x])F[++fc]=J[x],cnt[fc]=0;
		++cnt[fc],x/=P[J[x]];
	}
}

int N,M,A[MX];
struct Node
{
	int i,c;
	Node(){}
	Node(int i_,int c_){i=i_,c=c_;}
};
vector<Node> stk[MX];

struct SegmentTree{int v,l,r;}T[MX*300];
int tc,ts;
#define li T[i].l
#define ri T[i].r
#define mid ((l+r)>>1)
void Copy(int& i){if(i<=ts)T[++tc]=T[i],i=tc;}
void Modify(int& i,int l,int r,int a,int x)
{
	Copy(i);
	if(l==r){T[i].v=x;return;}
	if(a<=mid)Modify(li,l,mid,a,x);
	else Modify(ri,mid+1,r,a,x);
	T[i].v=(ll)T[li].v*T[ri].v%Mod;
}
int Ask(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return T[i].v;
	ll res=1;
	if(a<=mid)res*=Ask(li,l,mid,a,b);
	if(b>mid)res*=Ask(ri,mid+1,r,a,b);
	return res%Mod;
}

int I[MX];

void Init()
{
	Fr(i,1,N)
	{
		ts=tc,I[i]=I[i-1];
		Factor(A[i]);
		Fr(j,1,fc)
		{
			int f=F[j],c=1;
			Fr(k,1,cnt[j])c*=P[f];
			for(int k=c;k>1&&stk[f].size();)
			{
				Node p=stk[f].back();
				if(k>=p.c)stk[f].pop_back(),A[p.i]/=p.c,k/=p.c;
				else stk[f].back().c/=k,A[p.i]/=k,k=1;
				Modify(I[i],1,N,p.i,A[p.i]);
			}
			stk[f].push_back(Node(i,c));
		}
		Modify(I[i],1,N,i,A[i]);
	}
}


int main()
{
	IO.rd(N);
	Fr(i,1,N)IO.rd(A[i]);
	
	Euler();
	Init();
	
	IO.rd(M);
	int las=0;
	Fr(i,1,M)
	{
		int l,r;
		IO.rd(l),IO.rd(r);
		l=(l+las)%N+1,r=(r+las)%N+1;
		if(l>r)swap(l,r);
		IO.wd(las=Ask(I[r],1,N,l,r)),IO.wc('\n');
	}
	
	return 0;
}