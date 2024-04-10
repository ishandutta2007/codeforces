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
int a[N],b[N];

vector <int> G[N];

bool Med;
int main() {
	fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		n=rd();
		int k=0;
		rep(i,1,n) {
			b[i]=rd();
			if(b[i]<i) cmax(k,b[i]);
			else cmax(k,i);
		}
		rep(i,0,n+1) G[i].clear();
		rep(i,1,n) G[b[i]].pb(i);
		rep(i,0,n+1) sort(G[i].begin(),G[i].end(),[&](int x,int y){ return G[x].size()>G[y].size(); });
		int u=G[0].size()?0:n+1,v=0;
		printf("%d\n",k);
		rep(i,1,n) {
			if(!G[u].size()) u=v;
			//cout<<"#"<<u<<' '<<G[u].size()<<endl;
			v=G[u].back(),G[u].pop_back();
			printf("%d ",v);
		}
		puts("");
	}
}