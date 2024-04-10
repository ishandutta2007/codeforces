#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N=2e5+5;

vector<pii> v[N];
bool vis[N];

void solve(){
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int mn=1;
	rep(i,1,n+1){
		cin>>a[i];
		if(a[mn]>a[i])mn=i;
	}
	rep(i,1,n+1){
		if(mn==i)continue;
		v[mn].pb({i,a[mn]+a[i]});
		v[i].pb({mn,a[mn]+a[i]});
	}
	rep(i,0,m){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	int ans=0;
	set<pii> s;
	s.insert({0,mn});
	while(!s.empty()){
		int w=s.begin()->fr,x=s.begin()->sc;
		s.erase(s.begin());
		if(vis[x])continue;
		vis[x]=1;
		ans+=w;
		for(pii y:v[x]){
			if(vis[y.fr])continue;
			s.insert({y.sc,y.fr});
		}
	}
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}