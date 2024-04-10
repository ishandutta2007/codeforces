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

const int N=10100;

int seta(int n){
	return n;
}
int setb(int n){
	return n + 5005;
}

vector<int> v[N];
bool vis[N];
int match[N];

vector<int> stk;

bool dfs(int z){
	vis[z] = 1;
	stk.pb(z);
	for(int x:v[z]){
		// cout << "z x" << "\n";
		if(x == match[z]) continue;
		stk.pb(x);
		if(match[x] == -1){
			return 1;
		}
		else if(!vis[match[x]]){
			if(dfs(match[x])) return 1;
		}
		stk.ppb();
	}
	stk.ppb();
	return 0;
}

void solve(){
	mem1(match);
	int n,m;
	cin >> n >> m;
	vector<int> p(n+1), c(n+1);
	rep(i,1,n+1){
		cin >> p[i];
	}
	rep(i,1,n+1){
		cin >> c[i];
	}
	int d;
	cin >> d;
	vector<int> k(d);
	rep(i,0,d){
		cin >> k[i];
	}
	reverse(all(k));
	set<int> s(all(k));
	
	auto add_person = [&](int i){
		int x = setb(c[i]);
		int y = seta(p[i]);
		v[x].pb(y);
		v[y].pb(x);
	};
	
	rep(i,1,n+1){
		if(s.count(i)) continue;
		add_person(i);
	}
	
	int cur = 0;
	vector<int> ans;
	for(int added: k){
		bool ok = 1;
		while(ok){
			ok = 0;
			rep(i,0,cur+1){
				vis[i] = 0;
			}
			stk.clear();
			// if aug path found, ok = 1
			if(dfs(cur)){
				ok = 1;
				int z = sz(stk);
				for(int i = 0; i < z; i += 2){
					match[stk[i]] = stk[i+1];
					match[stk[i+1]] = stk[i];
				}
			}
			if(ok) cur++;
		}
		ans.pb(cur);
		add_person(added);
	}
	
	reverse(all(ans));
	for(int x:ans){
		cout << x << "\n";
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