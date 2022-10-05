#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
namespace lct{
	int fa[N],t[N][2],mx[N],s[N],w[N];
	int isr(int x){
		return t[fa[x]][0]!=x&&t[fa[x]][1]!=x;
	}
	void up(int x){
		int lc=t[x][0],rc=t[x][1];
		s[x]=s[lc]+w[x]+s[rc];
		mx[x]=max(mx[rc],s[rc]+max(w[x],w[x]+mx[lc]));
	}
	#define B(x) (t[fa[x]][1]==x)
	void rot(int x){
		int y=fa[x],z=fa[y],f=B(x);
		if(!isr(y)){t[z][B(y)]=x;}fa[x]=z;
		fa[t[y][f]=t[x][f^1]]=y;
		fa[t[x][f^1]=y]=x,up(y),up(x);
	}
	void spl(int x){
		for(;!isr(x);rot(x)) if(!isr(fa[x]))
			rot(B(x)^B(fa[x])?x:fa[x]);
	}
	void acc(int x0){
		for(int y=0,x=x0;x;y=x,x=fa[x])
			spl(x),t[x][1]=y,up(x);
		spl(x0);
	}
	void init(int n){
		rep(i,0,n) mx[i]=s[i]=w[i]=-1;
		s[0]=w[0]=0;
	}
}
int in[N],out[N],id[N],n,Q,clk;
set<int> s;
vi e[N];

void dfs(int u){
	id[in[u]=++clk]=u;
	for(auto v:e[u]) dfs(v);
	out[u]=clk;
}

int main(){
	read(n),read(Q);
	lct::init(n);
	rep(i,2,n){
		read(lct::fa[i]);
		e[lct::fa[i]].pb(i);
	}
	dfs(1);
	for(int op,x;Q;Q--){
		read(op),read(x);
		if(op==1){
			lct::acc(x),lct::w[x]++,lct::up(x);
			s.insert(in[x]);
		}
		else if(op==2){
			auto it=s.lower_bound(in[x]);
			for(int y;it!=s.end()&&*it<=out[x];s.erase(it++))
				y=id[*it],lct::acc(y),lct::w[y]=-1,lct::up(y);
			lct::acc(x),lct::w[x]+=-lct::mx[x]-1,lct::up(x);
			s.insert(in[x]);
		}
		else lct::acc(x),puts(lct::mx[x]>=0?"black":"white");
	}
	return 0;
}