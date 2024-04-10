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


bool solve(){
	int n;
	scanf("%d", &n);
	VV(int) d;
	initvv(d, n, n);
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j){
		scanf("%d", &d[i][j]);
	}

	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j){
		if(d[i][j] != d[j][i]){ return false; }
		if((d[i][j] == 0) != (i == j)){ return false; }
	}

	VV(pii) G(n);
	priority_queue<tuple<int,int,int>> pq;
	vector<char> used(n);
	for(int i = 1; i < n; ++i){
		pq.emplace(-d[0][i], 0, i);
	}
	used[0] = 1;
	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();
		int c = -get<0>(tp), u = get<1>(tp), v = get<2>(tp);
		if(used[v]){ continue; }
		used[v] = 1;
		G[u].emplace_back(v, c);
		G[v].emplace_back(u, c);
		for(int i = 0; i < n; ++i){
			if(!used[i]){
				pq.emplace(-d[v][i], v, i);
			}
		}
	}

	vector<LL> ds;
	for(int i = 0; i < n; ++i){
		queue<int> q;
		ds.assign(n, -1);
		ds[i] = 0;
		q.push(i);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(cauto p : G[u]){
				if(ds[p.first] < 0){
					ds[p.first] = ds[u] + p.second;
					q.push(p.first);
				}
			}
		}
		for(int j = 0; j < n; ++j){
			if(ds[j] != d[i][j]){
				return false;
			}
		}
	}

	return true;
}


int main(){
	puts(solve() ? "YES" : "NO");
}