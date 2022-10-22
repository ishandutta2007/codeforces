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

const int N=1010,INF=1e9+10;
const int dx[]={1,1,-1,-1,2,2,-2,-2};
const int dy[]={2,-2,2,-2,1,-1,1,-1};

int n,m,opt;
int x=-2,y=-2;
void input(){ 
	x=rd(),y=rd(); 
	if(x==-1) exit(0);
}
void CB(){ puts("BLACK"),fflush(stdout),input(); }
void CW(){ puts("WHITE"),fflush(stdout); }

struct Bfser{
	int dis[N][N],pre[N][N];
	int QX[N*N],QY[N*N],L,R;
	int u,v;
	int Reach() {
		int a=abs(u-x),b=abs(y-v);
		if(a>b) swap(a,b);
		return a==1 && b==2;
	}
	void Bfs(int x,int y){
		u=x,v=y;
		QX[L=R=1]=x,QY[1]=y,pre[x][y]=-1,dis[x][y]=1;
		for(;L<=R;) {
			x=QX[L],y=QY[L++];
			//cout<<x<<' '<<y<<' '<<dis[x][y]<<endl;
			rep(i,0,7) {
				int x1=x+dx[i],y1=y+dy[i];
				if(x1<1 || y1<1 || x1>n || y1>m || dis[x1][y1]) continue;
				dis[x1][y1]=dis[x][y]+1,QX[++R]=x1,QY[R]=y1,pre[x1][y1]=i;
			}
		}
	}
	void Go(int d,int k=1) {
		if(Reach()) printf("%d %d\n",x,y),fflush(stdout),exit(0);
		printf("%d %d\n",u+=dx[d],v+=dy[d]),fflush(stdout);
		if(k) input();
	}
	void Go(int x,int y,int k) {
		vector <int> s;
		while(~pre[x][y]) {
			int t=pre[x][y];
			s.pb(t),x-=dx[t],y-=dy[t];
		}
		drep(i,s.size()-1,0) Go(s[i],k+i);
	}
} B,W;

int main(){
	n=rd(),m=rd();
	int x1=rd(),y1=rd(),x2=rd(),y2=rd();
	W.Bfs(x1,y1),B.Bfs(x2,y2);
	int f=((x1+y1)&1)!=((x2+y2)&1);
	if(W.dis[n/2][m/2]<=B.dis[n/2+1][m/2] && (f || W.dis[n/2][m/2]<B.dis[n/2][m/2])) {
		CW(),x=x2,y=y2,W.Go(n/2,m/2,0);
	} else if(B.dis[n/2+1][m/2]<W.dis[n/2][m/2] && (B.dis[n/2+1][m/2]<W.dis[n/2+1][m/2]-1 || !f)) {
		CB(),B.Go(n/2+1,m/2,0);
	} else if(f) {
		CW(),x=x2,y=y2,W.Go(n/2+1,m/2,1);
		W.Go(2),W.Go(5),W.Go(7,0);
	} else {
		CB(),B.Go(n/2,m/2,1);
		B.Go(0),B.Go(7),B.Go(5,0);
	}
}