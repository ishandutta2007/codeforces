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

const int32_t M=1e3+5;

const int N=1e5+5;

int n,m,q;
bool grid[M][M];
bool zero[M];
int cnt[M];

vector<int> v[N];
int t[N];
int x[N];
int y[N];
int ans[N];

void dfs(int z,int p){
	ans[z] = ans[p];
	if(t[z] == 3){
		ans[z] -= cnt[x[z]];
		cnt[x[z]] = m - cnt[x[z]];
		zero[x[z]] ^= 1;
		ans[z] += cnt[x[z]];
	}
	bool changed = 0;
	if(t[z] == 1){
		if(grid[x[z]][y[z]] == zero[x[z]]){
			changed = 1;
			grid[x[z]][y[z]] = !zero[x[z]];
			cnt[x[z]]++;
			ans[z]++;
		}
	}
	if(t[z] == 2){
		if(grid[x[z]][y[z]] != zero[x[z]]){
			changed = 1;
			grid[x[z]][y[z]] = zero[x[z]];
			cnt[x[z]]--;
			ans[z]--;
		}
	}
	for(int a:v[z]){
		dfs(a,z);
	}
	if(t[z] == 3){
		cnt[x[z]] = m - cnt[x[z]];
		zero[x[z]] ^= 1;
	}
	if(t[z] == 1){
		if(changed){
			grid[x[z]][y[z]] = zero[x[z]];
			cnt[x[z]]--;
		}
	}
	if(t[z] == 2){
		if(changed){
			grid[x[z]][y[z]] = !zero[x[z]];
			cnt[x[z]]++;
		}
	}
}

void solve(){
	cin >> n >> m >> q;
	
	rep(i,1,q+1){
		int type;
		cin >> type;
		t[i] = type;
		if(type == 4){
			int k;
			cin >> k;
			v[k].pb(i);
			continue;
		}
		v[i-1].pb(i);
		cin >> x[i];
		if(type == 3){
			continue;
		}
		cin >> y[i];
	}
	
	for(int z:v[0]){
		dfs(z,0);
	}
	
	rep(i,1,q+1){
		cout << ans[i] << "\n";
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