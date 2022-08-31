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

const int N=0;



void solve(){
	int n,s;
	cin >> n >> s;
	
	int mn = 2 * n - 1;
	int mx = n * (n + 1) / 2;
	
	if(s < mn || s > mx){
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	
	int L = 1, U = n-1;
	int ans = n-1;
	while(L <= U){
		int m = (L + U) / 2;
		int tot = 0;
		
		int xn = 1;
		int dep = 1;
		int tmp = n;
		while(tmp){
			int v = min(tmp, xn);
			tot += dep * v;
			tmp -= v;
			xn *= m;
			dep++;
		}
		
		if(tot <= s){
			ans = m;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
	}
	
	vector<int> p(n+1);
	vector<int> deg(n+1);
	vector<vector<int>> ver_at_dep(n + 1);
	deg[1] = 1;
	ver_at_dep[1].pb(1);
	rep(i,2,n+1){
		p[i] = i - 1;
		deg[i] = 1;
		ver_at_dep[i].pb(i);
	}
	deg[n] = 0;
	
	int dec = n * (n + 1) / 2 - s;
	int cur = 1;
	
	for(int i = n; dec > 0; i--){
		deg[p[i]]--;
		if(ver_at_dep[cur].empty()){
			cur++;
		}
		
		int x = cur;
		int tmp = i - 1 - cur;
		if(tmp > dec){
			x = i - 1 - dec;
		}
		
		int z = ver_at_dep[x].back();
		p[i] = z;
		deg[z]++;
		ver_at_dep[x+1].pb(i);
		if(deg[z] == ans) ver_at_dep[x].ppb();
		dec -= i - 1 - x;
	}
	
	rep(i,2,n+1){
		cout << p[i] << " ";
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