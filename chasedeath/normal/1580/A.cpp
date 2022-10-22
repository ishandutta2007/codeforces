#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

bool Mbe;
const int N=410,INF=1e9+10;

int n,m;
int s[N][N];
int c[N][N];

/*int S(int x1,int y1,int x2,int y2){
	x1--,y1--;
	return c[x2][y2]-c[x1][y2]-c[x2][y1]+c[x1][y1];
}

int IS(int x1,int y1,int x2,int y2){
	return (x2-x1+1)*(y2-y1+1)-S(x1,y1,x2,y2);
}*/


bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		n=rd(),m=rd();
		rep(i,1,n) rep(j,1,m) scanf("%1d",s[i]+j);
		int ans=16;
		rep(i,1,n) rep(j,1,m) c[i][j]=c[i-1][j]+s[i][j];
		rep(x,1,n) rep(y,x+4,n) {
			int mi=1e9;
			rep(r,4,m) {
				mi=min(mi+c[y-1][r-1]-c[x][r-1]+!s[x][r-1]+!s[y][r-1],c[y-1][r-1]-c[x][r-1]+c[y-1][r-2]-c[x][r-2]+(y-x-1)-(c[y-1][r-3]-c[x][r-3])+!s[x][r-2]+!s[y][r-2]+!s[x][r-1]+!s[y][r-1]);
				cmin(ans,mi+(y-x-1)-(c[y-1][r]-c[x][r]));
			}
		}
		printf("%d\n",ans);
	}
}