#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=1e5+100;

struct Node{int x;ll v;}d[MX];
bool cmp(const Node& a,int b){return a.x<b;}
int cnt,L,R;
int Split(int x)
{
	//int i=lower_bound(d,d+cnt,x,cmp)-d;
	Fr(i,1,cnt)if(x<=d[i].x)
	{
		if(d[i].x==x)return i;
		memmove(d+i+1,d+i,(cnt-i)*sizeof(Node));
		d[i].x=x,++cnt;
		return i;
	}
}
void Visit(int l,int r){L=Split(l-1)+1,R=Split(r);}
void Assign(int l,int r,ll v)
{
	Visit(l,r);
	memmove(d+L,d+R,(cnt-R)*sizeof(Node));
	d[L].v=v,cnt-=R-L;
}

void Add(int l,int r,ll v)
{
	Visit(l,r);
	Fr(i,L,R)d[i].v+=v;
}
Node tmp[MX];
bool operator<(const Node& a,const Node& b){return a.v<b.v;}
ll Kth(int l,int r,int k)
{
	Visit(l,r);
	int c=0;
	Fr(i,L,R)tmp[++c].v=d[i].v,tmp[c].x=d[i].x-d[i-1].x;
	sort(tmp+1,tmp+1+c);
	Fr(i,1,c)
	{
		if(k<=tmp[i].x)return tmp[i].v;
		else k-=tmp[i].x;
	}
}
ll qpow(ll a,ll p,ll mod)
{
	ll r=1;
	a%=mod;
	while(p)
	{
		if(p&1)r=r*a%mod;
		a=a*a%mod,p>>=1;
	}
	return r%mod;
}
ll PowSum(int l,int r,ll p,ll mod)
{
	Visit(l,r);
	ll res=0;
	Fr(i,L,R)res+=(d[i].x-d[i-1].x)*qpow(d[i].v,p,mod),res%=mod;
	return res;
}

ll seed;
ll Rand()
{
	ll r=seed;
	seed=(seed*7+13)%1000000007;
	return r;
}

int N,M;
ll V;

void Init()
{
	cnt=1;
	Fr(i,1,N)d[cnt].x=i,d[cnt].v=Rand()%V+1,++cnt;
}
/*
void Print()
{
	//printf("%d\n",cnt);
	Fo(i,1,cnt)
	{
		if(i!=1)printf("-");
		printf("[%d,%d|%lld]",d[i-1].x+1,d[i].x,d[i].v);
	}
	printf("\n");
}
*/
int main()
{
	scanf("%d%d%lld%lld",&N,&M,&seed,&V);
	Init();
	int op,l,r;
	ll x,y;
//	Print();
	Fr(i,1,M)
	{
		op=Rand()%4+1;
		l=Rand()%N+1;
		r=Rand()%N+1;
		if(l>r)swap(l,r);
		if(op==3)x=Rand()%(r-l+1)+1;
		else x=Rand()%V+1;
		if(op==4)y=Rand()%V+1;
		/*
		printf("op=%d [%d, %d] x=%lld",op,l,r,x);
		if(op==4)printf(" y=%lld",y);
		putchar('\n');
		*/
		switch(op)
		{
		case 1:Add(l,r,x);break;
		case 2:Assign(l,r,x);break;
		case 3:printf("%lld\n",Kth(l,r,x));break;
		case 4:printf("%lld\n",PowSum(l,r,x,y));break;
		}
//		Print();
	}
}
//
//int main()
//{
//	cnt=5;
//	
//	Assign(3,9,100);
//	Add(4,7,55);
//	
//	printf("%d  L=%d R=%d\n",cnt,L,R);
//	Fo(i,0,cnt)printf("[%d:%lld] ",d[i].x,d[i].v);putchar('\n');
//	return 0;
//}