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

const int N=1000005,inf=1e9+99;
priority_queue<pii,vector<pii>,greater<pii> > Q;
int f[N][2],u[N],v[N],l[N],r[N],n,m,cnt,ans=inf;
vi e[N][2];

void push(int k,int t){
	int p=(t+1)%2;
	if(t+1>=f[k][p]||t>=r[k]) return;
	f[k][p]=t+1,Q.push(mp(f[k][p],k<<1|p));
}

void upd(int u,int t,int lim){
	int p=t%2; if(lim%2!=p) lim--;
	if(u==n) ans=min(ans,t);
	while(!e[u][p].empty()&&l[e[u][p].back()]<=lim){
		int v=e[u][p].back();
		e[u][p].pop_back();
		push(v,l[v]<=t?t:(l[v]%2!=p?l[v]+1:l[v]));
	}
}

int main(){
	read(n),read(cnt);
	rep(i,1,cnt){
		read(u[m]),read(v[m]);
		read(l[m]),read(r[m]);
		f[m][0]=f[m][1]=inf;
		e[u[m]][0].pb(m++);
		u[m]=v[m-1],v[m]=u[m-1];
		l[m]=l[m-1],r[m]=r[m-1];
		f[m][0]=f[m][1]=inf;
		e[u[m]][0].pb(m++);
	}
	rep(u,1,n){
		sort(e[u][0].begin(),e[u][0].end(),[&](int a,int b){
			return l[a]>l[b];
		});
		e[u][1]=e[u][0];
	}
	upd(1,0,0);
	while(!Q.empty()){
		int k=Q.top().se,t=Q.top().fi;
		Q.pop();
		if(f[k>>1][k&1]!=t) continue;
		k>>=1,upd(v[k],t,r[k]);
	}
	printf("%d\n",ans>=inf?-1:ans);
	return 0;
}