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

int deg[N];
int v[N];
int t[N];


vector<int> pr;
int dfs(int z){
	if(z == 0 || deg[z] > 1) return 0;
	
	return 1 + dfs(v[z]);
}

void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> t[i];
	}
	rep(i,1,n+1){
		int x;
		cin >> x;
		v[i] = x;
		deg[x]++;
	}
	int ans = 0;
	int ansg;
	rep(i,1,n+1){
		if(t[i] == 1){
			int tmp = dfs(i);
			if(tmp > ans){
				ans = tmp;
				ansg = i;
			}
		}
	}
	cout << ans << "\n";
	int x = ansg;
	rep(i,0,ans){
		pr.pb(x);
		x = v[x];
	}
	reverse(all(pr));
	for(int x:pr){
		cout << x << " ";
	}
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
	//cin>>t;
	while(t--) solve();
	return 0;
}