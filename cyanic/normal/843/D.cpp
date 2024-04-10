#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n):i++)
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
int a[N],b[N],c[N],f[N],n,m,Q;
vector<pii> e[N];
ll d[N];

void dij(){
	typedef pair<ll,int> pli;
	priority_queue<pli,vector<pli>,greater<pli> > Q;
	memset(d,0x3f,sizeof d);
	Q.push(mp(0,1)),d[1]=0;
	for(;!Q.empty();){
		int u=Q.top().se;
		ll now=Q.top().fi; Q.pop();
		if(now>d[u]) continue;
//		printf("## d[%d] = %lld\n",u,d[u]);
		for(auto t:e[u]){
			if(d[u]+t.se<d[t.fi]){
				d[t.fi]=d[u]+t.se;
				Q.push(mp(d[t.fi],t.fi));
			}
		}
	}
}

vi tax[N];
void Clear(vi &x){
	vi y; swap(x,y);
}
void flu(int lim){
	rep(i,0,lim) Clear(tax[i]);
	rep(i,1,n){
		e[i].clear();
		f[i]=lim;
	}
	rep(i,1,m){
		e[a[i]].pb(mp(b[i],c[i]-(d[b[i]]-d[a[i]])));
	}
	f[1]=0;
	tax[0].pb(1);
	int cur=0;
	for(;cur<=lim;){
		for(;cur<=lim&&!tax[cur].size();cur++);
		if(cur>lim) break;
		int u=tax[cur].back();
		tax[cur].pop_back();
		if(cur>f[u]) continue;
//		printf("### f[%d] = %d\n",u,f[u]);
		for(auto t:e[u]){
			if(f[u]+t.se<f[t.fi]){
				f[t.fi]=f[u]+t.se;
				tax[f[t.fi]].pb(t.fi);
			}
		}
	}
	rep(i,1,n) d[i]+=f[i];
}

int main(){
	read(n),read(m),read(Q);
	rep(i,1,m){
		read(a[i]),read(b[i]),read(c[i]);
		e[a[i]].pb(mp(b[i],c[i]));
	}
	dij();
	rep(i,1,Q){
		int ty,x,y;
		read(ty),read(x);
		if(ty==1){
			printf("%lld\n",d[x]>1e18?-1:d[x]);
		}
		else{
			rep(i,1,x) read(y),c[y]++;
			flu(x);
		}
	}
	return 0;
}