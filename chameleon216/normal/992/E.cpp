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

const int MB=1<<20;
template<typename T>
void rd(T& x)
{
    char c=getchar(),l=0;
    for(x=0;!isdigit(c);c=getchar())l=c;
    for(;isdigit(c);c=getchar())x=x*10-'0'+c;
    if(l=='-')x=-x;
}
template<typename T>
void wd(T x)
{
    static char stk[128];
    if(x<0)putchar('-'),x=-x;
    int tp=0;
    do stk[++tp]=x%10+'0';
    while(x/=10);
    while(tp)putchar(stk[tp--]);
}

const int MX=200100;
int N,M,A[MX];

ll val[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Build(int i,int l,int r)
{
	if(l==r){val[i]=A[l];return;}
	Build(li,l,mid);
	Build(ri,mid+1,r);
	val[i]=val[li]+val[ri];
}
void Modify(int i,int l,int r,int a,int x)
{
	if(l==r){val[i]=x;return;}
	if(a<=mid)Modify(li,l,mid,a,x);
	else Modify(ri,mid+1,r,a,x);
	val[i]=val[li]+val[ri];
}
void Bin(int i,int l,int r,ll& s,int& res)
{
	if(res!=-1)return;
	if(val[i]<s){s+=val[i];return;}
	if(l==r)
	{
		if(val[i]==s)res=l;
		s+=val[i];
		return;
	}
	Bin(li,l,mid,s,res);
	Bin(ri,mid+1,r,s,res);
}


int main()
{
	rd(N),rd(M);
	Fr(i,1,N)rd(A[i]);
	Build(1,1,N);
	Fr(i,1,M)
	{
		int a,x;
		rd(a),rd(x);
		Modify(1,1,N,a,x);
		
		ll s=0;
		int res=-1;
		Bin(1,1,N,s,res);
		wd(res),putchar('\n');
	}
	return 0;
}