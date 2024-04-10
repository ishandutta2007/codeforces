#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <utility>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
#define Mset(i,x) memset((i),(x),sizeof(i))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int MX=250000;
int N,M;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

void exgcd(ll a,ll b,ll& x,ll& y,ll& g)
{
	if(b)exgcd(b,a%b,y,x,g),y-=x*(a/b);
	else g=a,x=1,y=0;
}

ll Mul(ll a,ll b,ll mod)
{
	a=(a%mod+mod)%mod,b=(b%mod+mod)%mod;
	return ((ull)a*b-(ull)((ld)a*b/mod)*mod+mod)%mod;
}


struct Data
{
	ll a,b; // x === a (mod b)
	Data(){}
	Data(ll a_,ll b_){a=a_,b=b_;}
};
Data operator+(const Data& d1,const Data& d2)
{
	if(d1.b==-1||d2.b==-1)return Data(-1,-1);
	ll c=d2.a-d1.a,x,y,g;
	exgcd(d1.b,d2.b,x,y,g);
	if(c%g)return Data(-1,-1);
	ll b_=d2.b/g;
	x=Mul(x,c/g,b_);
	ll B=d1.b/g*d2.b,A=d1.a+d1.b*x;
	return Data(A%B,B);
}




struct Seg
{
	Data d;
	int l,r;
}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
void pushup(int i){T[i].d=T[li].d+T[ri].d;}
void Build(int i,int l,int r)
{
	T[i].l=l,T[i].r=r,T[i].d=Data(0,1);
	if(l==r)return;
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
}
void Modify(int i,int a,Data x)
{
	if(T[i].l==T[i].r){T[i].d=x;return;}
	if(a<=T[li].r)Modify(li,a,x);
	else Modify(ri,a,x);
	pushup(i);
}
int Bin(int i,Data sum)
{
	if(T[i].l==T[i].r)
	{
		Data now=T[i].d+sum;
		return now.b==-1?T[i].l+1:T[i].l;
	}
	Data now=T[ri].d+sum;
	if(now.b==-1)return Bin(ri,sum);
	else return Bin(li,now);
}


Data D[MX];
int dc;
int Calc()
{
	int ans=0;
	Build(1,1,dc);
	Fr(r,1,dc)
	{
		Modify(1,r,D[r]);
		int l=Bin(1,Data(0,1));
	//	printf("[%d %d]",l,r);
		ans=max(ans,r-l+1);
	}
//	putchar('\n');
	return ans;
}


int K[MX];
vector<pair<int,int> > V[MX];


int Solve(int j)
{
//	printf("\nSolve %d\n",j);
	vector<pair<int,int> > &v=V[j];
	int sz=v.size(),ans=0;
	if(!sz)return 0;
	Fo(i,0,sz)
	{
		D[++dc]=Data(v[i].second,K[v[i].first]);
		if(i==sz-1||v[i+1].first-v[i].first>1)
			ans=max(ans,Calc()),dc=0;
	}
	return ans;
}



int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)
	{
		int x;
		scanf("%d",K+i);
		Fr(j,1,K[i])
		{
			scanf("%d",&x);
			V[x].push_back(make_pair(i,j));
		}
	}
	Fr(i,1,M)printf("%d\n",Solve(i));
	return 0;
}