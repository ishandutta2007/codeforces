#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,avx")

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
const int INF = 1e9 + 47;
const LL LINF = 1LL * INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> gen;
vector<vector<int>> mx;
vector<int> vec;

void rec(int where, int id){
	if (id == 10){
		bool was3 = 0, was7 = 0;
		for(auto i: vec){
			was3 |= i == 3;
			was7 |= i == 7;
		}
		
		if (!was3 || !was7)
			gen.PB(vec);
		return;
	}
	
	FOR(curr, 0, mx[where][id] + 1){
		rec(where, id + 1);
		vec.PB(id);
	}
	
	FOR(curr, 0, mx[where][id] + 1){
		vec.pop_back();
	}
	
}

typedef __int128 Long;

int mult(int a, int b, int c){
	return (a * b) % c;
}

int power(int a, int b, int c){
	int r = 1;
	while(b){
		if (b & 1) r = mult(r, a, c);
		a = mult(a, a, c);
		b >>= 1;
	}
	
	return r;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, d; cin >> n >> d;
	vector<vector<int>> a(10);
	vector<int> b(n);
	FOR(i, 0, n){
		int x; cin >> x;
		b[i] = x;
		a[x % 10].PB(x);
	}
	
	FOR(i, 0, 10){
		sort(ALL(a[i]));
		reverse(ALL(a[i]));
	}
	
	if (d == 0){
		int r = 1;
		FOR(i, 0, n) r = (r * b[i]) % 10;
		if (r != d){
			cout << -1 << endl;
			return 0;
		}
		
		cout << n << endl;
		FOR(i, 0, n) cout << b[i] << ' ';
		cout << endl;
		return 0; 
	}
	
	if (d == 5){
		int r = 1;
		int c = 0;
		FOR(i, 0, n) if (b[i] % 2 == 1) c += 1, r = (r * b[i]) % 10;
		
		if (r != d){
			cout << -1 << endl;
			return 0;
		}
		
		cout << c << endl;
		FOR(i, 0, n) if (b[i] % 2 == 1) cout << b[i] << ' ';
		cout << endl;
		return 0; 
	}
	
	mx = vector<vector<int>>(2, vector<int>(10, 0));
	mx[0][2] = 3;
	mx[0][4] = 1;
	mx[0][8] = 3;
	FOR(it, 0, 2){
		mx[it][3] = 3;
		mx[it][7] = 3;
		mx[it][9] = 1;
	}
	
	rec(d % 2, 2);
	a[0].clear();
	a[5].clear();
	if (d % 2 == 1){
		FOR(i, 0, 10) if (i % 2 == 0) a[i].clear();
	}
	
	Long best = LINF * (Long) LINF;
	vector<int> best_vec;
	
	for(auto v: gen){
		vector<int> cnt(10);
		FOR(j, 0, 10) cnt[j] = SZ(a[j]);
		for(auto i: v) cnt[i] -= 1;
		bool ok = 1;
		FOR(j, 0, 10) if (cnt[j] < 0) ok = 0;
		if (!ok) continue;
		
		int r = 1;
		ok = 0;
		FOR(j, 0, 10) if (cnt[j]){
			ok = 1;
			r = mult(r, power(j, cnt[j], 10), 10);
		} 		
		
		if (!ok || r != d){
			continue;
		}
		
		Long curr = 1;
		vector<vector<int>> popped(10);
		for(auto i: v){
			int x = a[i].back();
			a[i].pop_back();
			curr *= x;
			popped[i].PB(x);
		}
		
		FOR(i, 0, 10){
			reverse(ALL(popped[i]));
			for(auto x: popped[i]){
				a[i].PB(x);
			}
		}
		
		if (curr < best){
			best = curr;
			best_vec = v;
		}
	}
	
	if (best == LINF * (Long) LINF){
		cout << -1 << endl;
		return 0;
	}	
	
	vector<int> ans;
	vector<int> v = best_vec;
	
	vector<int> cnt(10);
	FOR(j, 0, 10) cnt[j] = SZ(a[j]);
	for(auto i: v) cnt[i] -= 1;
	bool ok = 1;
	FOR(j, 0, 10) if (cnt[j] < 0) ok = 0;
	assert(ok);
	
	FOR(j, 0, 10) FOR(i, 0, cnt[j]) ans.PB(a[j][i]);
	
	cout << SZ(ans) << endl;
	for(auto i: ans) cout << i << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}