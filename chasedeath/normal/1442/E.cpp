#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
//typedef long double db;
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

const int N=2e5+10,INF=1e9+10;

int n,a[N];
vector <int> G[N];
int deg[N];
queue <int> Q[3];
int vis[N];

void Del(int u){
	//cout<<"Del "<<u<<endl;
	for(int v:G[u]) if(!vis[v] && --deg[v]<=1) vis[v]=1,Q[a[v]].push(v);
}

int Calc(int k){
	rep(i,1,n) deg[i]=G[i].size(),vis[i]=0;
	rep(i,1,n) if(deg[i]<=1) Q[a[i]].push(i),vis[i]=1;
	int ans=0;
	while(1) {
		while(!Q[0].empty()) Del(Q[0].front()),Q[0].pop();
		if(Q[k].size()) {
			//puts("---1---");
			while(!Q[k].empty()) {
				Del(Q[k].front()),Q[k].pop();
				while(!Q[0].empty()) Del(Q[0].front()),Q[0].pop();
			}
			ans++;
		} else if(Q[3-k].size()) {
			//puts("---2---");
			while(!Q[3-k].empty()) {
				Del(Q[3-k].front()),Q[3-k].pop();
				while(!Q[0].empty()) Del(Q[0].front()),Q[0].pop();
			}
			ans++;
		} else break;
	}
	//puts("-----");
	return max(ans,1);
}


int main(){
	rep(_,1,rd()) {
		rep(i,1,n=rd()) a[i]=rd(),G[i].clear();
		rep(i,2,n){
			int u=rd(),v=rd();
			G[u].pb(v),G[v].pb(u);
		}
		int a=Calc(1),b=Calc(2);
		printf("%d\n",min(a,b));
	}
}