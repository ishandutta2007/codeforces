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

const int N=5e5+10,INF=1e9+10;

int n,m;
vector <int> G[N],T;
int deg[N];
struct cmp{ bool operator () (const int x,const int y) const { return mp(deg[x],x)>mp(deg[y],y); } };
set <int,cmp> st;
int p[N],q[N];
vector <int> V[N];
int rt[N],id[N],sz[N];
int Find(int x,int y){ 
	auto p=lower_bound(G[x].begin(),G[x].end(),y);
	return p!=G[x].end() && *p==y;
}

int main(){
	rep(_,1,rd()) {
		n=rd(),m=rd(),st.clear();
		rep(i,1,n) G[i].clear(),deg[i]=0;
		rep(i,1,m) {
			int u=rd(),v=rd();
			G[u].pb(v),G[v].pb(u);
			deg[u]++,deg[v]++;
		}
		rep(i,1,n) st.insert(i);
		rep(i,1,n) sort(G[i].begin(),G[i].end());
		int c=0;
		drep(i,n,1) {
			if(deg[*st.begin()]<i-1) break;
			int u=*st.begin(); st.erase(st.begin());
			//printf("Pop %d\n",u);
			p[u]=q[u]=++c;
			for(int i:st) deg[i]--;
		}
		T.clear();
		//puts("Unsolved");
		//for(int i:st) cout<<i<<' ';
		//puts("");
		for(int i:st) T.pb(i);
		for(int i:T) id[i]=0;
		int rc=0;
		for(int i:T) if(!id[i]) {
			for(int j:T) {
				if(i==j || Find(i,j)) continue;
				//cout<<"$"<<i<<' '<<j<<endl;
				if(!id[j]) sz[++rc]=2,rt[rc]=i,id[i]=id[j]=rc;
				else if(rt[id[j]]==j) sz[id[i]=id[j]]++;
				else if(sz[id[j]]>2) sz[id[j]]--,sz[++rc]=2,rt[rc]=i,id[i]=id[j]=rc;
				else rt[id[j]]=j,sz[id[i]=id[j]]++;
				break;
			}
		}
		rep(i,1,rc) V[i].clear();
		for(int i:T) if(rt[id[i]]!=i) V[id[i]].pb(i);
		//rep(i,1,rc) assert(V[i].size()>0);
		rep(i,1,rc) {
			p[rt[i]]=++c;
			for(int j:V[i]) p[j]=++c,q[j]=c-1;
			q[rt[i]]=c;
		}
		rep(i,1,n) printf("%d ",p[i]); 
		puts("");
		rep(i,1,n) printf("%d ",q[i]); 
		puts("");
	}
}