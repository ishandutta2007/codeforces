#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x,y) for(int i=H[x][y];i;i=E[i].nx)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define IO_FAST 1

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

const int MX=510,MY=610000;

struct Query{int x,y,nx,ans;}E[MY];
int H[MX][MX],ec;
void Add(int xa,int ya,int xb,int yb)
{
	E[++ec].x=xa,E[ec].y=ya,E[ec].nx=H[xb][yb],H[xb][yb]=ec;
}

int N,M,Q;
char S[MX][MX];


#define A_(j) ((j)>>6)
#define B_(j) ((j)&63)
struct Bitset
{
	ull x[MX][8];
	void set(int i,int j)
	{
		x[i][A_(j)]|=1ull<<B_(j);
	}
	int get(int i,int j)
	{
		return (x[i][A_(j)]>>B_(j))&1;
	}
	void clear()
	{
		memset(x,0,sizeof(x));
	}
}B[2][MX];

void Merge(Bitset& c,Bitset& a,Bitset& b,int n,int m)
{
	int m_=A_(m);
	Fr(i,1,n)
	{
#define Loop(j) c.x[i][j]=a.x[i][j]|b.x[i][j]
		switch(m_)
		{
		case 7:Loop(7);
		case 6:Loop(6);
		case 5:Loop(5);
		case 4:Loop(4);
		case 3:Loop(3);
		case 2:Loop(2);
		case 1:Loop(1);
		case 0:Loop(0);
		}
	}
}



void Solve()
{
	Bitset *a=B[0],*b=B[1];
	Fr(i,1,N)
	{
		Fr(j,1,M)
		{
			if(S[i][j]=='#')b[j].clear();
			else Merge(b[j],a[j],b[j-1],i,j),b[j].set(i,j);
			Fe(k,i,j)E[k].ans=b[j].get(E[k].x,E[k].y);
		}
		swap(a,b);
	}
}


int main()
{
	IO>>N>>M;
	Fr(i,1,N)IO>>(S[i]+1);
	IO>>Q;
	int xa,ya,xb,yb;
	Fr(i,1,Q)
	{
		IO>>xa>>ya>>xb>>yb;
		Add(xa,ya,xb,yb);
	}
	Solve();
	Fr(i,1,Q)IO<<(E[i].ans?"Yes":"No")<<'\n';
	return 0;
}