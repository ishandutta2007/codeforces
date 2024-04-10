#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e5+5;

vector<pii> v[N];

int a[N];

void dfs(int z,int p=0,int m=0){
	for(pii x:v[z]){
		if(x.fr == p) continue;
		a[x.sc] = 2+m;
		dfs(x.fr,z,!m);
	}
}

void solve(){
	int n;
	cin >> n;
	
	rep(i,1,n+1){
		v[i].clear();
	}
	
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb({y,i-1});
		v[y].pb({x,i-1});
	}
	
	int s;
	rep(i,1,n+1){
		if(sz(v[i]) > 2){
			cout << "-1\n";
			return;
		}
		if(sz(v[i]) == 1) s = i;
	}
	
	dfs(s);
	
	rep(i,0,n-1){
		cout << a[i] << " ";
	}
	cout << "\n";
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}