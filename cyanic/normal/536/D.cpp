#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,int> pli;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const ll inf=1e18;
const int N=2005;
ll f[N][N],g[N][N],s[N][N],c[N][N];
ll w[N],x[N],y[N],X[N],Y[N];
int n,m,S,T,cx,cy;
vector<pii> e[N];

void dij(int s,ll d[]){
	priority_queue<pli,vector<pli>,greater<pli> > Q;
	fill(d+1,d+n+1,inf);
	Q.push(mp(d[s]=0,s));
	while(!Q.empty()){
		int u=Q.top().se; 
		ll dis=Q.top().fi; Q.pop();
		if(d[u]!=dis)continue;
		for(auto v:e[u])
			if(d[u]+v.se<d[v.fi])
				Q.push(mp(d[v.fi]=d[u]+v.se,v.fi));
	}
}

void init(){
	dij(S,x),dij(T,y);
	X[++cx]=inf,Y[++cy]=inf;
	rep(i,1,n)
		X[++cx]=x[i],Y[++cy]=y[i];
	sort(X+1,X+cx+1);
	cx=unique(X+1,X+cx+1)-X;
	sort(Y+1,Y+cy+1);
	cy=unique(Y+1,Y+cy+1)-Y;
	rep(i,1,n){
		x[i]=lower_bound(X+1,X+cx+1,x[i])-X;
		y[i]=lower_bound(Y+1,Y+cy+1,y[i])-Y;
		s[x[i]][y[i]]+=w[i];
		c[x[i]][y[i]]+=1;
	}
	per(i,cx,1)per(j,cy,1){
		s[i][j]+=s[i+1][j]+s[i][j+1]-s[i+1][j+1];
		c[i][j]+=c[i+1][j]+c[i][j+1]-c[i+1][j+1];
	}
}

ll solve(){
	per(i,cx,1)per(j,cy,1){
		if(c[i][j]==c[i+1][j]){
			f[i][j]=f[i+1][j];
		}
		else{
			f[i][j]=max(f[i+1][j]+s[i][j]-s[i+1][j],
						s[i][j]-s[i+1][j]-g[i+1][j]);
		}
		if(c[i][j]==c[i][j+1]){
			g[i][j]=g[i][j+1];
		}
		else{
			g[i][j]=max(g[i][j+1]+s[i][j]-s[i][j+1],
						s[i][j]-s[i][j+1]-f[i][j+1]);
		}
	}
	return f[1][1];
}

int main(){
	read(n),read(m);
	read(S),read(T);
	rep(i,1,n)read(w[i]);
	rep(i,1,m){
		int a,b,c;
		read(a),read(b),read(c);
		e[a].pb(mp(b,c));
		e[b].pb(mp(a,c));
	}
	init();
	ll res=solve();
	if(res>0)puts("Break a heart");
	else if(res<0)puts("Cry");
	else puts("Flowers");
	return 0;
}