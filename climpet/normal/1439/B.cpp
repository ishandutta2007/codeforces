#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <iomanip>
#include <unordered_set>

using namespace std;

#define cauto const auto&
#define ALL(v) begin(v),end(v)

namespace{
typedef long long LL;
typedef pair<int,int> pii;

template <class Con>
string concat(const Con &c, const string &spr){
	stringstream ss;
	typename Con::const_iterator it = c.begin(), en = c.end();
	bool fst = true;
	for(; it != en; ++it){
		if(!fst){ ss << spr; }
		fst = false;
		ss << *it;
	}
	return ss.str();
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<unordered_set<int>> G(n + 1);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		G[a].insert(b);
		G[b].insert(a);
	}
	if(k * (k - 1LL) / 2 > m){
		cout << "-1\n";
		return;
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	set<int> rem;
	for(int i = 1; i <= n; ++i){
		pq.emplace(G[i].size(), i);
		rem.insert(i);
	}

	vector<int> vs;
	vector<char> ex(n + 1);
	while(!pq.empty()){
		int sz = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(!rem.count(u) || (int)G[u].size() != sz){ continue; }
		if(sz >= k){
			cout << "1 " << rem.size() << "\n" << concat(rem, " ") << "\n";
			return;
		}
		if(sz == k - 1){
			vs.assign(ALL(G[u]));
			vs.push_back(u);
			bool ok = true;
			for(int i = 0; i < k && ok; ++i)
			for(int j = 0; j < i; ++j)
			if(!G[vs[i]].count(vs[j])){
				ok = false;
				break;
			}
			if(ok){
				cout << "2\n" << concat(vs, " ") << "\n";
				return;
			}
		}
		for(int x : G[u]){
			G[x].erase(u);
			pq.emplace(G[x].size(), x);
		}
		rem.erase(u);
	}
	cout << "-1\n";
}

void mainmain(){
	int t;
	for(cin >> t; t--; ){
		solve();
	}
}



}
int main() try{
	ios::sync_with_stdio(false); cin.tie(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	mainmain();
}
catch(const exception &e){
	cerr << "exception: " << e.what() << endl;
	abort();
}
catch(...){
	cerr << "exception" << endl;
	abort();
}