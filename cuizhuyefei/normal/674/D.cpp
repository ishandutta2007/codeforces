#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
int n,q,p[N],d[N];ll t[N],ans[N];
multiset<ll>glo;
struct Ass{
	ll lzy;multiset<ll>Set;
	inline void ins(ll x){//real=x
		x-=lzy;
		if(Set.empty())glo.insert(x+lzy),glo.insert(x+lzy);
		else{
			if(x<*Set.begin())glo.erase(glo.find(*Set.begin()+lzy)),glo.insert(x+lzy);
			if(x>*Set.rbegin())glo.erase(glo.find(*Set.rbegin()+lzy)),glo.insert(x+lzy);
		}
		Set.insert(x);
	}
	inline void era(ll x){//real=x
		x-=lzy;assert(Set.find(x)!=Set.end());
		Set.erase(Set.find(x));
		if(Set.empty())glo.erase(glo.find(x+lzy)),glo.erase(glo.find(x+lzy));
		else{
			if(x<*Set.begin())glo.erase(glo.find(x+lzy)),glo.insert(*Set.begin()+lzy);
			if(x>*Set.rbegin())glo.erase(glo.find(x+lzy)),glo.insert(*Set.rbegin()+lzy);
		}
	}
	inline void addlzy(ll x){
		if(!Set.empty()){
			glo.erase(glo.find(*Set.begin()+lzy));glo.erase(glo.find(*Set.rbegin()+lzy));
			glo.insert(*Set.begin()+lzy+x);glo.insert(*Set.rbegin()+lzy+x);
		}
		lzy+=x;
	}
}a[N];
inline void add(int u, ll x){
	a[p[u]].era(ans[u]+a[p[u]].lzy);ans[u]+=x;a[p[u]].ins(ans[u]+a[p[u]].lzy);
}
inline void cut(int u, int v){
	add(p[u],t[u]/(d[u]+1)-t[u]/(d[u]+2));
	add(u,t[u]/(d[u]+2)*(d[u]+1)-t[u]/(d[u]+1)*d[u]);
	add(v,-(t[u]/(d[u]+2)));a[u].era(ans[v]+a[p[v]].lzy);
	a[u].addlzy(t[u]/(d[u]+1)-t[u]/(d[u]+2));ans[v]-=t[u]/(d[u]+1)-t[u]/(d[u]+2);
}
inline void link(int u, int v){
	add(p[u],t[u]/(d[u]+3)-t[u]/(d[u]+2));
	add(u,t[u]/(d[u]+2)*(d[u]+1)-t[u]/(d[u]+3)*(d[u]+2));
	a[u].addlzy(t[u]/(d[u]+3)-t[u]/(d[u]+2));ans[v]-=t[u]/(d[u]+3)-t[u]/(d[u]+2);
	a[u].ins(ans[v]+a[p[v]].lzy);add(v,(t[u]/(d[u]+3)));
}
void ini(){
	static Vi e[N];rep(i,1,n)e[i].pb(p[i]),e[p[i]].pb(i);
	rep(u,1,n){
		ans[u]+=t[u]-t[u]/(SZ(e[u])+1)*SZ(e[u]);
		rep(i,0,SZ(e[u])-1)ans[e[u][i]]+=t[u]/(SZ(e[u])+1);
	}
	rep(i,1,n)a[p[i]].ins(ans[i]);
}
int main() {
	read(n);read(q);
	rep(i,1,n)read(t[i]);
	rep(i,1,n)read(p[i]),d[p[i]]++;
	ini();
	while(q--){
		int op,u,v;read(op);
		if(op==1){
			read(u);read(v);int x=v,y=p[u];
			add(v,t[u]/(d[u]+2));add(p[u],-(t[u]/(d[u]+2)));
		//	cerr<<"qwq "<<ans[u]+a[p[u]].lzy<<endl;
			cut(p[u],u);
		//	cerr<<"qwq "<<ans[u]+a[p[u]].lzy<<endl;
			ans[u]+=a[p[u]].lzy-a[v].lzy;p[u]=v;
			link(v,u);
			d[x]++;d[y]--;
		//	a[p[u]].era(ans[u]+a[p[u]].lzy);
		//	p[u]=v;
		//	a[p[u]].ins(ans[u]+a[p[u]].lzy);
		}
		else if(op==2){
			read(u);printf("%lld\n",ans[u]+a[p[u]].lzy);
		}
		else{
			printf("%lld %lld\n",*glo.begin(),*glo.rbegin());
		}
	}
	return 0;
}