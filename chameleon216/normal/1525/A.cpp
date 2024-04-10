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


int gcd(int a,int b){return b?gcd(b,a%b):a;}


int main()
{
	int N;
	scanf("%d",&N);
	int M=100-N;
	int G=gcd(N,M);
	printf("%d\n",100/G);
	return 0;
}