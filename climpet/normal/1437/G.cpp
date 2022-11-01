#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

using namespace std;

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

namespace{
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T> inline T &chmin(T &x, const T &y){ return x = min(x, y); }
template <class T> inline T &chmax(T &x, const T &y){ return x = max(x, y); }
template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}
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

template <class Con, class Fun>
vector<typename Con::value_type> cfilter(const Con &c, Fun f) {
	vector<typename Con::value_type> ret;
	typename Con::const_iterator it = c.begin(), en = c.end();
	for(; it != en; ++it){
		if(f(*it)){
			ret.emplace_back(*it);
		}
	}
	return ret;
}
#if __cplusplus >= 201103L
template <class Con, class Fun>
auto cmap(const Con &c, Fun f) -> vector<decltype(f(*c.begin()))> {
	vector<decltype(f(*c.begin()))> ret;
	ret.reserve(c.size());
	for(const auto &x: c){
		ret.emplace_back(f(x));
	}
	return ret;
}
#endif


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()
#define tget(t,i) get<i>(t)

#define MOD 1000000007LL
#define EPS 1e-8

struct ahocorasick{
	typedef char keytype;
	struct node{
		int fail, jump;
		bool marked;
		std::map<keytype,int> nxt;
		map<int,int> freq;
		int mx;
		node() : fail(-1), jump(-1), marked(false), mx(-1) {
		}
		
		bool haskey(keytype c){
			return nxt.count(c);
		}
		int &getnext(keytype c){
			return nxt[c];
		}
		void mark(){
			marked = true;
			++freq[0];
			mx = 0;
		}
		std::map<keytype,int> &getchildren(){
			return nxt;
		}
		
		void update(int a, int b){
			auto it = freq.find(a);
			assert(it != freq.end());
			if(--it->second == 0){
				freq.erase(it);
			}
			++freq[b];
			mx = freq.rbegin()->first;
		}
	};
	
	std::vector<node> nodes;
	ahocorasick(){
		nodes.emplace_back();
	}
	template <class Seq>
	int add(const Seq &seq){
		int u = 0;
		for(keytype c : seq){
			if(!nodes[u].haskey(c)){
				nodes[u].getnext(c) = nodes.size();
				nodes.emplace_back();
			}
			u = nodes[u].getnext(c);
		}
		nodes[u].mark();
		return u;
	}
	int nextnode(int u, keytype c){
		while(u >= 0){
			if(nodes[u].haskey(c)){
				return nodes[u].getnext(c);
			}
			u = nodes[u].fail;
		}
		return 0;
	}
	void build(){
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(const auto &p : nodes[u].getchildren()){
				keytype c = p.first;
				int v = p.second;
				q.push(v);
				int f = nextnode(nodes[u].fail, c);
				nodes[v].fail = f;
				nodes[v].jump = nodes[f].marked ? f : nodes[f].jump;
			}
		}
	}
};

void mainmain(){
	int n, m;
	cin >> n >> m;

	ahocorasick ac;
	string s;
	vector<int> idx(n);
	for(int i = 0; i < n; ++i){
		cin >> s;
		idx[i] = ac.add(s);
	}
	ac.build();

	vector<int> vals(n);
	for(int i = 0; i < m; ++i){
		int tp;
		cin >> tp;
		if(tp == 1){
			int a, x;
			cin >> a >> x;
			--a;
			int u = idx[a];
			ac.nodes[u].update(vals[a], x);
			vals[a] = x;
		}
		else{
			int ans = -1;
			int u = 0;
			cin >> s;
			for(char c : s){
				u = ac.nextnode(u, c);
				for(int v = u; v >= 0; v = ac.nodes[v].jump){
					chmax(ans, ac.nodes[v].mx);
				}
			}
			cout << ans << '\n';
		}
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