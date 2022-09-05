#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 466666;
int n,m,cho[N];Vi e[N],ne[N];
bool fd(int x, int y){for(int i:e[x])if(i==y)return 1;return 0;}
int main() {
	int t;read(t);while(t--){
		read(n);read(m);
		rep(i,0,n+1)cho[i]=-1,e[i].clear(),ne[i].clear();
		while(m--){
			int u,v;read(u);read(v);
			bool fd=0;for(int x:e[u])fd|=x==v;
			if(!fd)e[u].pb(v),ne[v].pb(u);
		}
		rep(i,1,n)if(cho[i]!=1){
			int t=0;for(int j:ne[i])t|=cho[j]==1;if(!t&&cho[i]==0)cho[i]=-1;
			if(cho[i]!=-1)continue;
			per(j,SZ(e[i])-1,0)if(cho[e[i][j]]>=0)
				e[i].erase(e[i].begin()+j);
			cho[i]=1;
			if(SZ(e[i])==1)cho[e[i][0]]=0;
			else if(SZ(e[i])==2){
				int x=e[i][0],y=e[i][1];
				if(fd(y,x))swap(x,y);
				if(fd(x,y)){
					cho[x]=1;cho[y]=0;
					for(int u:e[x])cho[u]=0;
				}
				else{
					cho[x]=cho[y]=1;
					for(int u:e[x])cho[u]=0;
					for(int u:e[y])cho[u]=0;
				}
			}
		}
		Vi res;rep(i,1,n)if(cho[i]==0)res.pb(i);
		
		printf("%d\n",SZ(res));
		for(auto x:res)printf("%d ",x);puts("");
		assert(SZ(res)*7<=4*n);
	}
	return 0;
}