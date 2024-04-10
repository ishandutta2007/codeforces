#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

const int N=2e5+5;


int n,m;

vector<int> v[N];
int par[N];
int tin[N];
int tout[N];
int tim=0;
void dfs(int z,int p){
	tim++;
	tin[z]=tim;
	par[z]=p;
	for(int x:v[z]){
		if(x==p)continue;
		dfs(x,z);
	}
	tout[z]=tim;
}

void solve(){
	cin>>n>>m;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,1);
	// rep(i,1,n+1){
	// 	cout<<tin[i]<<" "<<tout[i]<<"\n";
	// }
	rep(zz,0,m){
		int k;
		cin>>k;
		int a=1;
		bool f=1;
		rep(i,0,k){
			int x;
			cin>>x;
			x=par[x];
			if(tin[x]<=tin[a] && tout[x]>=tin[a]){
				continue;
			}
			swap(a,x);
			if(tin[x]<=tin[a] && tout[x]>=tin[a]){
				continue;
			}
			f=0;
		}
		if(f){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}