#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const bool local = false;
vector<int> guess;
int queries;

int ask(vector<int>& a){
	queries++;
	assert(queries <= 12);
	if (local == true){
		int mx = 0;
		for(auto i: a){
			setmax(mx, guess[i]);
		}
		
		return mx;
	}
	
	sort(ALL(a));
	cout << "? " << SZ(a);
	for(auto i: a){
		cout << " " << i;
	}
	
	cout << endl;
	fflush(stdout);
	int x;
	cin >> x;
	assert(x != -1);
	return x;
}

int n, k;
vector<vector<int>> s;

inline int get(int x){
	vector<int> all;
	FOR(i, 0, x){
		for(auto j: s[i]){
			all.PB(j);
		}
	}
		
	return ask(all);
}

inline int getN(int x){
	vector<int> all(x);
	iota(ALL(all), 1);
	return ask(all);
}

void solve(vector<int>& ans){
	cout << "!";
	for(auto i: ans){
		cout << ' ' << i;
	}
	
	cout << endl;
	fflush(stdout);
	string resp;
	cin >> resp;	
}

void solve(){
	cin >> n >> k;
	s.clear();
	s.resize(k);
	int C = 0;
	vector<int> belong(n + 1, -1);
	FOR(i, 0, k){
		int sz;
		cin >> sz;
		s[i].resize(sz);
		for(auto& j: s[i]){
			cin >> j;
			belong[j] = i;
			C++;
		}
	}
	
	vector<int> ans(k, -1);
	
	int mx = getN(n);
	int l = 0, r = n, m;
	while(r - l > 1){
		m = (l + r) >> 1;
		int tut = getN(m);
		if (tut == mx){
			r = m;
		}else{
			l = m;
		}
	}
	
	if (belong[l + 1] == -1){
		ans.assign(k, mx);
		solve(ans);
		return;
	}
	
	l = belong[l + 1];
	
	VI all(n);
	iota(ALL(all), 1);
	set<int> AA(ALL(all));
	for(auto i: s[l]) AA.erase(i);
	vector<int> rest(ALL(AA));
	
	FOR(i, 0, k) if (i != l){
		ans[i] = mx;
	}
	
	ans[l] = ask(rest);
	solve(ans);
}

int main()
{	
	guess.assign(1001, 0);
	iota(ALL(guess), 0);
	
	int t;
	cin >> t;
	while(t--){
		queries = 0;
		solve();
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}