#include <bits/stdc++.h>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)

#define MULTIPLE 1
#define IO_FAST 0
#define LONG_LONG 0

using namespace std;
typedef int sint;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;


const int BufSize=1<<21;
struct FastIO
{
	char ibuf[BufSize+10],*p,*e;
	char obuf[BufSize+10],*q,stk[128];

#if IO_FAST
	FastIO(){q=obuf;}
	~FastIO(){fwrite(obuf,1,q-obuf,stdout);}

	int getChar()
	{
		if(p==e)p=ibuf,e=ibuf+fread(ibuf,1,BufSize,stdin);
		return p==e?EOF:*p++;
	}
	void putChar(int c)
	{
		if(q-obuf==BufSize)fwrite(obuf,1,BufSize,stdout),q=obuf;
		*q++=c;
	}
#else
	int getChar(){return getchar();}
	void putChar(int c){putchar(c);}
#endif

	FastIO& operator>>(char& c)
	{
		do{c=getChar();}while(isspace(c));
		return *this;
	}
	FastIO& operator>>(char* s)
	{
		*s=' ';
		while(isspace(*s))*s=getChar();
		while(!isspace(*s))*++s=getChar();
		*s=0;
		return *this;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}

	FastIO& operator<<(char c)
	{
		putChar(c);
		return *this;
	}
	FastIO& operator<<(char* s)
	{
		while(*s)putChar(*s++);
		return *this;
	}
	FastIO& operator<<(const char* s)
	{
		while(*s)putChar(*s++);
		return *this;
	}
	template<typename T>
	FastIO& operator<<(T x)
	{
		int tp=0;
		if(x<0)x=-x,putChar('-');
		do{stk[++tp]=x%10,x/=10;}while(x);
		while(tp)putChar(stk[tp--]+'0');
		return *this;
	}
}IO;

int mian();
int main()
{
	int t=1;
#if MULTIPLE
	IO>>t;
#endif
	while(t --> 0)mian();
}

#if LONG_LONG
#define int long long
#define main BASILISK;signed mian
#else
#define main mian
#endif

template<typename T>
inline T Abs(T x){return x>=0?x:-x;}

template<typename T>
inline bool max_eq(T& x,T y){return x<y?(x=y,1):0;}
inline bool max_eq(ll& x,sint y){return x<y?(x=y,1):0;}

template<typename T>
inline bool min_eq(T& x,T y){return x>y?(x=y,1):0;}
inline bool min_eq(ll& x,sint y){return x>y?(x=y,1):0;}

const sint Inf=0x3f3f3f3f;
const ll InfL=0x3f3f3f3f3f3f3f3fll;
const double Eps=1e-13;
const int MOD=
998244353;
//1000000007;

template<int size>
struct Bit
{
	int sz,v[size];
	Bit(){Fill(v,0);}
	void set_size(int s){sz=s;}
	void add(int i,int x)
	{ while(i<=sz)v[i]+=x,i+=(i&-i); }
//	void add(int l,int r,int x) //Add[l,r] Ask[x]
//	{ add(l,x),add(r+1,-x); }
	int ask(int i)
	{
		int r=0;
		while(i)r+=v[i],i-=(i&-i);
		return r;
	}
	int ask(int l,int r) //Add[x] Ask[l,r]
	{ return ask(r)-ask(l-1); }
};

const int MX=700000;

int N,M;

struct Pt
{
	int p;
	char f;
	int id;
}P[MX];
bool operator<(const Pt& a,const Pt& b)
	{return a.p<b.p;}

int I[MX],ic;
int stk[MX],tp;
int T[MX];

void Solve(int x)
{
	ic=0,tp=0;
	Fr(i,1,N)if((P[i].p&1)==x)I[++ic]=i;
	Fr(i_,1,ic)
	{
		int i=I[i_];
		if(P[i].f=='R')stk[++tp]=i;
		else
		{
			if(tp)
			{
				int j=stk[tp--];
				if(P[j].f=='R')T[P[i].id]=T[P[j].id]=(P[i].p-P[j].p)/2;
				else T[P[i].id]=T[P[j].id]=(P[i].p+P[j].p)/2;
			}
			else stk[++tp]=i;
		}
	}
	//printf("%d\n",tp);
	while(tp>1)
	{
		int i=stk[tp--],j=stk[tp--];
		if(P[i].f==P[j].f)
			T[P[i].id]=T[P[j].id]=(M-P[i].p+M-P[j].p)/2;
		else
			T[P[i].id]=T[P[j].id]=(M+M-P[i].p+P[j].p)/2;
	}
}


int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",&P[i].p);
	Fr(i,1,N)scanf(" %c",&P[i].f);
	Fr(i,1,N)P[i].id=i;
	sort(P+1,P+1+N);
	
	Fr(i,1,N)T[i]=-1;
	Solve(0);
	Solve(1);
	Fr(i,1,N)printf("%d ",T[i]);
	putchar('\n');
	
	Fr(i,1,N)P[i].p=P[i].f=0;
	
	return 0;
}