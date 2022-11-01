/*
5 5
1 2 3
1 3 3
2 3 4
3 4 4
4 5 5
*/

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

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


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

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8



int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<tuple<int,int,int> > es(m);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		es[i] = make_tuple(w, u, v);
	}
	sort(ALL(es));

	vector<int> a(n + 1), b(n + 1), c(n + 1, -1);
	for(int i = 0; i < m; ++i){
		int u, v, w;
		tie(w, u, v) = es[i];

		if(c[u] < w){
			a[u] = max(a[u], b[u]);
		}
		if(c[v] < w){
			a[v] = max(a[v], b[v]);
		}
		
		if(b[v] <= a[u]){
			b[v] = a[u] + 1;
			c[v] = w;
		}
	}
	
	int ans = max(*max_element(ALL(a)), *max_element(ALL(b)));
	printf("%d\n", ans);
}