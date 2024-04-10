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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8

typedef unsigned long long ULL;
#define BASE 1000000093ull

vector<string> s;
vint par;
vvint chld;
ULL ans;
ULL hash, pw;
string t;


void dfs(int v, vector<ULL> &h){
	int sz = h.size();
	for(int i = 0; i < s[v].size(); ++i){
		h.push_back(h.back() * BASE + s[v][i]);
		if(h.size() > t.size()){
			int k = h.size() - t.size() - 1;
			if(h.back() - h[k] * pw == hash){
				++ans;
			}
		}
	}
	
	for(int i = 0; i < chld[v].size(); ++i){
		dfs(chld[v][i], h);
	}
	
	h.resize(sz);
}


int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	par.resize(n + 1);
	chld.resize(n + 1);
	s.resize(n + 1);
	for(int i = 2; i <= n; ++i){
		cin >> par[i] >> s[i];
		chld[par[i]].push_back(i);
	}

	cin >> t;
	pw = 1;
	for(int i = 0; i < t.size(); ++i){
		hash = hash * BASE + t[i];
		pw *= BASE;
	}

	vector<ULL> h(1, 0);
	dfs(1, h);
	cout << ans << endl;
}