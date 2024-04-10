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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

namespace ha{
	const int M=19260817;
	ll u[M]; int h[M],l[M],v[M],sz;
	void init(){
		for(;sz;sz--) h[u[sz]%M]=0;
	}
	void ins(ll key,int val){
		int k=key%M;
		u[++sz]=key,v[sz]=val,l[sz]=h[k],h[k]=sz;
	}
	int ask(ll key){
		for(int k=h[key%M];k;k=l[k])
			if(u[k]==key) return v[k];
		return 0;
	}
}
const ll bas=998244353ll,bas2=2333ll;
const int N=300005;
int p[N],las[N],n,Q;
vector<pii> q[N];
vi a[N];

int rmain(){
	read(n),read(Q),ha::init();
	fill(p+1,p+n+1,0);
	int S=0;
	rep(i,1,Q){
		int K,x; a[i].clear();
		for(read(K),S+=K;K;K--) read(x),a[i].pb(x);
	}
	int T=80;
	rep(i,1,Q){
		if(a[i].size()>T) continue;
		int sz=a[i].size();
		REP(j,sz) rep(k,j+2,sz-1){
			ll owo=a[i][j]*bas+(a[i][j]^a[i][k])*bas2;
			int ret=ha::ask(owo);
			if(ret&&ret!=a[i][k-1]) return 1;
			else if(!ret) ha::ins(owo,a[i][k-1]);
		}
	}
	rep(i,1,Q){
		if(a[i].size()<=T) continue;
		int sz=a[i].size(),flag=0;
		REP(j,sz) p[a[i][j]]=j+1;
		rep(j,1,Q) if(i!=j){
			REP(k,a[j].size())
				if(p[a[j][k]]) q[p[a[j][k]]].pb(mp(j,k));
			las[j]=n;
		}
		REP(j,sz){
			for(auto id:q[j+1]){
				if(las[id.fi]+1<id.se) flag=1;
				las[id.fi]=id.se;
			}
			p[a[i][j]]=0,q[j+1].clear();
		}
		if(flag) return 1;
	}
	return 0;
}

int main(){
	int T; read(T);
	while(T--) puts(rmain()?"Human":"Robot");
	return 0;
}