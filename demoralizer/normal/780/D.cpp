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

string get1(string &s){
	string t = "";
	rep(i,0,3){
		t.pb(s[i]);
	}
	return t;
}

string get2(string &s, string &t){
	string z = "";
	z.pb(s[0]);
	z.pb(s[1]);
	z.pb(t[0]);
	return z;
}

void solve(){
	int n;
	cin >> n;
	map<string, int> f;
	vector<string> x,y;
	
	set<string> g;
	
	rep(i,0,n){
		string s,t;
		cin >> s >> t;
		string z = get1(s);
		f[z]++;
		x.pb(z);
		z = get2(s,t);
		y.pb(z);
	}
	
	vector<string> ans(n);
	
	rep(i,0,n){
		if(f[x[i]] > 1){
			if(g.count(y[i])){
				cout << "NO";
				return;
			}
			ans[i] = y[i];
			g.insert(y[i]);
		}
	}
	
	map<string, vector<pair<string,int>>> graph;
	map<string, int> deg;
	set<string> alive;
	
	rep(i,0,n){
		if(f[x[i]] == 1){
			graph[x[i]].pb({y[i],i});
			graph[y[i]].pb({x[i],i});
			deg[x[i]]++;
			deg[y[i]]++;
			alive.insert(x[i]);
			alive.insert(y[i]);
		}
	}
	
	for(string s:g){
		if(alive.count(s)){
			alive.erase(s);
			for(auto zz:graph[s]){
				deg[zz.fr]--;
			}
		}
	}
	
	set<pair<int, string>> st;
	for(string s:alive){
		st.insert({deg[s],s});
	}
	
	while(!st.empty()){
		string s = st.begin()->sc;
		st.erase(st.begin());
		alive.erase(s);
		bool found = 0;
		for(auto zz:graph[s]){
			if(!alive.count(zz.fr) && ans[zz.sc] == ""){
				ans[zz.sc] = s;
				found = 1;
				break;
			}
		}
		
		
		if(!found)
		for(auto zz:graph[s]){
			if(ans[zz.sc] == ""){
				ans[zz.sc] = s;
				break;
			}
		}
		
		
		for(auto zz:graph[s]){
			st.erase({deg[zz.fr],zz.fr});
			deg[zz.fr]--;
			if(alive.count(zz.fr)){
				st.insert({deg[zz.fr],zz.fr});
			}
		}		
	}
	
	for(string s:ans){
		if(s == ""){
			cout << "NO";
			return;
		}
	}
		
	cout << "YES\n";
	for(string s:ans){
		cout << s << "\n";
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