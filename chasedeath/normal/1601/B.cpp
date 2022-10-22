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
const int N=1e6+10,INF=1e9+10;

int n;
int A[N],B[N];
int F[N];
int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }

queue <Pii> que;
int dis[N][2];
Pii pre[N][2];
void push(int v,int a,int u,int b,int d) {
	if(dis[v][a]>d) {
		dis[v][a]=d,que.push(mp(v,a));
		pre[v][a]=mp(u,b);
	}
}

int seq[N],c;

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd();
	rep(i,1,n) F[i]=i;
	rep(i,1,n) A[i]=rd();
	rep(i,1,n) B[i]=rd();
	rep(i,0,n) dis[i][0]=dis[i][1]=INF;
	drep(i,n-1,n-A[n]) push(i,1,n,0,1),F[i]=i-1;
	while(!que.empty()) {
		int u=que.front().first,a=que.front().second; que.pop();
		//cout<<"!"<<u<<' '<<a<<endl;
		if(u==0) continue;
		if(a==1) {
			if(u+B[u]<=n) push(u+B[u],0,u,a,dis[u][a]+1);
		} else {
			for(int v=Find(u-1);v>=u-A[u];v=Find(v)) {
				push(v,1,u,a,dis[u][a]+1);
				if(v==0) break;
				F[v]=v-1;
			}
		}
	}
	if(dis[0][1]==INF) puts("-1");
	else {
		for(Pii i=mp(0,1);i.first!=n;i=pre[i.first][i.second]) {
			if(i.second==1) seq[++c]=i.first;
		}
		printf("%d\n",c);
		drep(i,c,1) printf("%d ",seq[i]);
	}
}