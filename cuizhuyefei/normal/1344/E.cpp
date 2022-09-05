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

const int N = 1e6+11;
int n,m;Vi e[N];int fa[N],ori[N];ll cost[N];
set<int>Set[N];
Pll a[9666666];int cnt;
void ins(int u, ll l, ll r){a[++cnt]=mp(l+1+cost[u],r+cost[u]);}
void dfs(int u){
	int son=0;
	for(int v:e[u]){
		cost[v]+=cost[u],dfs(v);
		if(SZ(Set[v])>=SZ(Set[son]))son=v;
	}
	/*set<int>a;
	for(int v:e[u])if(v!=son)a.insert(ALL(Set[v]));
	static int s[N];int sz=0;
	for(int x:a)s[++sz]=x;*/
	static Pii s[N];int sz=0;
	for(int v:e[u])if(v!=son)for(int x:Set[v])s[++sz]=mp(x,v);
	sort(s+1,s+sz+1);
	int mn=Set[ori[u]].empty()?2e9:*Set[ori[u]].begin();
	rep(i,1,sz){
		auto it=Set[son].lower_bound(s[i].fi);
		if(it!=Set[son].end()&&it!=Set[son].begin()){
			it--;
			int j=i;while(1){auto it1=it;it1++;if(j+1<=sz&&it1!=Set[son].end()&&s[j+1].fi<*(it1))j++;else break;}
			int lst=*it;
			rep(k,i,j){
				ins(u,lst,s[k].fi);
			//	b.pb(s[k].fi);
				while(k+1<=j&&s[k+1].se==s[k].se)k++;
				lst=s[k].fi;
			}
			ins(u,lst,*(++it));
		//	b.pb(*(++it));
		//	cerr<<"case1 "<<' '<<s[i].fi<<' ';for(int x:b)cerr<<x<<' ';cerr<<endl;
		//	rep(i,0,SZ(b)-2)ins(u,b[i],b[i+1]);
			i=j;
		}
		else if(it==Set[son].end()){
			it--;
			int j=sz;
		//	Vi b={*it};
			int lst=*it;
			rep(k,i,j){
				ins(u,lst,s[k].fi);while(k+1<=j&&s[k+1].se==s[k].se)k++;
				lst=s[k].fi;
			}
		//	cerr<<"case2 ";for(int x:b)cerr<<x<<' ';cerr<<endl;
		//	rep(i,0,SZ(b)-2)ins(u,b[i],b[i+1]);
			i=j;
		}
		else{
			int j=i;while(1){if(it!=Set[son].end()&&j+1<=sz&&s[j+1].fi<*(it))j++;else break;}
			int lst=-1;
			rep(k,i,j){
				if(lst!=-1)ins(u,lst,s[k].fi);while(k+1<=j&&s[k+1].se==s[k].se)k++;
				lst=s[k].fi;
			}
			ins(u,lst,*(it));//b.pb(*it);
		//	cerr<<"case3 ";for(int x:b)cerr<<x<<' ';cerr<<endl;
		//	rep(i,0,SZ(b)-2)ins(u,b[i],b[i+1]);
			i=j;
		}
	}
	for(int v:e[u])if(v!=son)Set[son].insert(ALL(Set[v]));
	if(SZ(Set[son])&&mn!=*Set[son].begin())ins(u,-cost[u],*Set[son].begin());
//	if(SZ(Set[son]))printf("%d ");
	Set[son].swap(Set[u]);
	Set[u].insert(ALL(Set[son]));Set[son].clear();
//	printf("%d:",u);for(int x:Set[u])printf("%d ",x);puts("");
}
priority_queue<ll,vector<ll>,greater<ll> >heap;
int main() {
	read(n);read(m);
	int A=0;
	rep(i,1,n-1){
		int u,v,d;read(u);read(v);read(d);
		if(i==1)A=u;
		fa[v]=u;cost[v]=d;e[u].pb(v);
		ori[u]=v;
	}
	rep(i,1,m){
		int s,t;read(s);read(t);Set[s].insert(t);
	}
	dfs(1);
	sort(a+1,a+cnt+1);//,[](Pll x, Pll y){return x.se<y.se;}
	/*a[cnt+1]=mp(0,1e18);
	set<ll>Set;
	
	rep(i,1,cnt){
		int j=i;while(j+1<=cnt&&a[j+1].se==a[i].se)j++;
		//[i,j] a[i].se
		bool gg=0;
		rep(k,i,j){
			ll p=
		}
		i=j;
	}*/
	ll t=0,gg=0;int p=0;
	while(1){
		t++;
		while(p+1<=cnt&&a[p+1].fi<=t)heap.push(a[++p].se);
	//	cerr<<t<<' '<<SZ(heap)<<endl;
		if(SZ(heap)&&heap.top()<t){
			gg=heap.top();break;
		}
		if(SZ(heap))heap.pop();
		else{
			if(p==cnt)break;
			t=a[p+1].fi-1;
		}
	}
	
	/*if(n==1e5&&m==1e5&&A==69944&&gg==1895){
		printf("%d\n",cnt);
		rep(i,1,cnt)if(a[i].se>=1894)printf("%lld %lld\n",a[i].fi,a[i].se);
		return 0;
	}*/
	
	if(!gg)printf("-1 %d\n",cnt);
	else{int ans=0;rep(i,1,cnt)ans+=a[i].se<gg;printf("%lld %d\n",gg,ans);}
	return 0;
}