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
int d[N];
int I[N];
int vis[N],F[N];
int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }
int query(int u) {
	printf("? %d\n",u);
	fflush(stdout);
	return rd();
}

bool Med;
int main() {
	fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		n=rd();
		rep(i,1,n) d[i]=rd(),I[i]=i,vis[i]=0,F[i]=i;
		sort(I+1,I+n+1,[&](int x,int y){ return d[x]>d[y]; });
		rep(i,1,n) {
			int u=I[i];
			if(vis[u]) continue;
			vis[u]=1;
			while(d[u]--) {
				int v=query(u);
				F[Find(v)]=Find(u);
				if(vis[v]) break;
				vis[v]=1;
			}
		}
		printf("! ");
		rep(i,1,n) printf("%d ",Find(i));
		puts("");
		fflush(stdout);
	}
}