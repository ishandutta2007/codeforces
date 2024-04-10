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
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char g()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void d(Tp& x)
	{
		char c=g(),l=0;
		for(x=0;!isdigit(c);c=g())l=c;
		for(;isdigit(c);c=g())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void w(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename Tp>
	void v(Tp x)
	{
		if(x<0)w('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)w(stk[tp--]);
	}
}IO;

const int MX=100100,MY=1010;
const int Base=10000019,Mod=1000000007;
int N,M;

struct Item{int v,w,l,r;}I[MX];
int ic;
int ans[MX],qc;

vector<int> V[MX*4];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Modify(int i,int l,int r,int a,int b,int id)
{
	if(b<l||r<a)return;
	if(a<=l&&r<=b)
	{
		V[i].push_back(id);
		return;
	}
	Modify(li,l,mid,a,b,id);
	Modify(ri,mid+1,r,a,b,id);
}

int dp[20][MX];
void Divide(int i,int l,int r,int tp)
{
	int *d=dp[tp];
	memcpy(d,dp[tp-1],(M+1)*sizeof(int));
	for(int id:V[i])
	{
		int v=I[id].v,w=I[id].w;
		Fl(k,M,v)d[k]=max(d[k],d[k-v]+w);
	}
	if(l==r)
	{
		ll h=0;
		Fl(k,M,1)h=(h*Base+d[k])%Mod;
		ans[l]=h;
		return;
	}
	Divide(li,l,mid,tp+1);
	Divide(ri,mid+1,r,tp+1);
}


int main()
{
	IO.d(ic),IO.d(M);
	Fr(i,1,ic)
	{
		I[i].l=1,I[i].r=-1;
		IO.d(I[i].w),IO.d(I[i].v);
	}
	IO.d(N);
	Fr(i,1,N)
	{
		int o;
		IO.d(o);
		if(o==1)
		{
			I[++ic].l=qc+1,I[ic].r=-1;
			IO.d(I[ic].w),IO.d(I[ic].v);
		}
		else if(o==2)
		{
			int id;
			IO.d(id);
			I[id].r=qc;
		}
		else if(o==3)++qc;
	}
	Fr(i,1,ic)
	{
		int l=I[i].l,r=I[i].r;
		if(r==-1)r=qc;
		Modify(1,1,qc,l,r,i);
	}
	Divide(1,1,qc,1);
	Fr(i,1,qc)IO.v(ans[i]),IO.w('\n');
	return 0;
}