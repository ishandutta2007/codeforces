//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx") 
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
typedef long double ld;
typedef long long ll;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define lo(x) ((x)&(-(x)))
#define trav(a, x) for (auto &a : x)
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
const ld Pi = 4*atan((ld)1);
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;

#define N 500050
#define MO 
int t,po,n,m,qx[N],qy[N];
vector<int>V[N],D[N],Vi[N],prx[N],pry[N];
char s[N];

void df(int x, int y, int di, int _x, int _y)
{
	if(Vi[x][y])return;
	Vi[x][y]=1;
	D[x][y]=di;
//	cerr<<x<<' '<<y<<' '<<di<<endl;
	qx[++t]=x;qy[t]=y;
	prx[x][y]=_x; pry[x][y]=_y;
	if(x>1&&y>1&&V[x-1][y-1])df(x-1,y-1,di,_x,_y);
	if(x>1&&y<m&&V[x-1][y+1])df(x-1,y+1,di,_x,_y);
	if(x<n&&y>1&&V[x+1][y-1])df(x+1,y-1,di,_x,_y);
	if(x<n&&y<m&&V[x+1][y+1])df(x+1,y+1,di,_x,_y);
}

int ch(int x, int y)
{
	if(x<1||x>n||y<1||y>m)return 1;
	return V[x-1][y]|V[x+1][y]|V[x][y-1]|V[x][y+1];
}

inline void _Sol_()
{
	read(n); read(m); 
	t=0;
	F(i,0,n+1)V[i].resize(m+2),D[i].resize(m+2),Vi[i].resize(m+2),prx[i].resize(m+2),pry[i].resize(m+2);
	
	F(i,1,n){
		scanf("%s",s+1);
		F(j,1,m)V[i][j] = s[j]=='#'?1:0;
	}
	
	F(i,0,n+1)
	F(j,0,m+1)D[i][j]=INF;
//	F(i,1,m)D[0][i]=D[n+1][i]=INF;
//	F(i,1,n)D[i][0]=D[i][m+1]=INF;
	
	F(i,1,n)if(V[i][1]){
		df(i,1,0,i,1);
	}
	
	F(i,1,n)if(V[i][1]){
//		df(i,1,0,i,1);
	}else if(!ch(i,1))df(i,1,1,i,1);
	
	F(i,1,t){
		int x=qx[i],y=qy[i];
		if(!ch(x-1,y-1))df(x-1,y-1,D[x][y]+1,x-1,y-1);
		if(!ch(x+1,y-1))df(x+1,y-1,D[x][y]+1,x+1,y-1);
		if(!ch(x-1,y+1))df(x-1,y+1,D[x][y]+1,x-1,y+1);
		if(!ch(x+1,y+1))df(x+1,y+1,D[x][y]+1,x+1,y+1);
	}
	
	int mi = INF;	
	F(i,1,n) chmin(mi,D[i][m]);
//	priE(mi);

	if(mi >= INF){   // +1
		puts("NO");//goto lll;
	}
else{

	puts("YES");
	int X;
	int Y = m;
	F(i,1,n){
		if(D[i][m]==mi) X = i;
	}

	while(Y!=1){
		int _x=prx[X][Y],_y=pry[X][Y];
		X=_x, Y=_y;
		V[X][Y]=1;
		if(D[X-1][Y-1]<D[X][Y])X=X-1,Y=Y-1;else
		if(D[X+1][Y-1]<D[X][Y])X=X+1,Y=Y-1;else
		if(D[X-1][Y+1]<D[X][Y])X=X-1,Y=Y+1;else
		if(D[X+1][Y+1]<D[X][Y])X=X+1,Y=Y+1;
	}
	V[X][Y]=1;
	
	F(i,1,n){
		F(j,1,m)if(V[i][j])putchar('#');else putchar('.');
		puts("");
	}
//lll:
}
	F(i,0,n+1)vector<int>().swap(V[i]); 
	F(i,0,n+1)vector<int>().swap(Vi[i]); 
	F(i,0,n+1)vector<int>().swap(D[i]); 
	F(i,0,n+1)vector<int>().swap(prx[i]); 
	F(i,0,n+1)vector<int>().swap(pry[i]); 
}

int main()
{
	int T=1; read(T);
	while(T--)_Sol_();
}
/*
1
9 3
...
..#
.#.
#..
..#
.#.
...
...
...



5 5
.....
.....
.....
.....
.....

2
2 4
.#..
..#.
2 4
..#.
.#..


1
3 3
#.#
...
.#.
1
2 4
.#..
..#.
*/