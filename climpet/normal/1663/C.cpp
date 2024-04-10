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
#include <random>

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
template <class T> inline bool chmin(T &x, const T &y){ if(y < x){ x = y; return true; } return false; }
template <class T> inline bool chmax(T &x, const T &y){ if(x < y){ x = y; return true; } return false; }
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

#if __cplusplus >= 201402L
#define lambda(e) ([&](const auto &_){ return (e); })
#define lambda2(e) ([&](const auto &_a, const auto &_b){ return (e); })
#endif


#define REP(i,n) for(LL i=0;i<LL(n);++i)
#define UPTO(i,f,t) for(LL i=f;i<=LL(t);++i)
#define DOWNTO(i,f,t) for(LL i=f;i>=LL(t);--i)
#define RALL(v) (v).rbegin(),(v).rend()
#define tget(t,i) get<i>(t)

#define MOD 1000000007LL
#define EPS 1e-8


void mainmain(){
	int n, s, t = 0;
	cin >> n;
	REP(i, n){
		cin >> s;
		t += s;
	}
	cout << t << "\n";
}



}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	mainmain();
}