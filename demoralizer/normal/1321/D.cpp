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

const int N=0;

vector<int> v[200005];
vector<int> u[200005];
int dis[200005];


void solve(){
	mem1(dis);
	int n,m;
	cin>>n>>m;
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		u[y].pb(x);
	}
	int k;
	cin>>k;
	vector<int> p(k);
	rep(i,0,k){
		cin>>p[i];
	}
	queue<pii> q;
	q.push({0,p.back()});
	while(!q.empty()){
		pii w=q.front();
		pii x={w.fr,w.sc};
		q.pop();
		if(dis[x.sc]!=-1)continue;
		dis[x.sc]=x.fr;
		for(int y:u[x.sc]){
		// cout<<x<<" "<<dis[x.sc]<<"\n";
			q.push({x.fr+1,y});
		}
	}
	// rep(i,1,n+1){
	// 	cout<<dis[i]<<"\n";
	// }
	int l=0,u=0;
	for(int i=1;i<sz(p);i++){
		if(dis[p[i-1]]<=dis[p[i]])l++;
		if(dis[p[i-1]] == dis[p[i]]+1){
			for(int y:v[p[i-1]]){
				if(y==p[i])continue;
				if(dis[y]==dis[p[i]]){
					u++;
					break;
				}
			}
		}
		else u++;
	}
	cout<<l<<" "<<u;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}