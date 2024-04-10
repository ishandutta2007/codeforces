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


typedef double db;
const int N = 19;
int n;
db x, y;

vector<string> gen[N];
map<string, int> mp[N];
int sz[N];
string now;

void rec(int id, int bal){
	
	if (id == n){
		mp[bal][now] = sz[bal]++;
		gen[bal].PB(now);	
		return;
	}	
	
	now += '(';
	rec(id + 1, bal + 1);
	now.pop_back();
	
	if (bal){
		now += ')';
		rec(id + 1, bal - 1);
		now.pop_back();
	}	
}

db area(string s){
	int res = 0;
	int h = 0;
	for(auto i: s){
		if (i == '(') h += 1;
		else h -= 1;
		res += h;
	}
	
	return res - h / 2.0;
}

db center_x(string s){
	int h = 0, a = 0;
	int res = 0;
	for(auto i: s){
		res += 6 * a * h + 3 * h;
		if (i == '(') res += 2 + 3 * a, h += 1;
		else res -= 2 + 3 * a, h -= 1;
		a += 1;
	}
	
	return res / 6.0;
}

db center_y(string s){
	int h = 0;
	int res = 0;
	for(auto i: s){
		res += 6 * h * h + 2;
		if (i == '(') res += 6 * h, h += 1;
		else res -= 6 * h, h -= 1;
	}
	
	return res / 6.0;
}

const db EPS = 1e-7;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	/*string s = "((()()()()((()()()))))";
	cout << fixed <<setprecision(12);
	cout << SZ(s) << ' ' << center_x(s) / area(s) << ' ' << center_y(s) / area(s) / 2 << endl;
	return 0;
	*/
	cin >> n >> x >> y;
	n >>= 1;
	rec(0, 0);
	
	FOR(balance, 0, n + 1){
		vector<pair<pair<db, db>, int>> all;
		for(auto s: gen[balance]){
			db Area = area(s);
			db X = center_x(s);
			db Y = center_y(s);
			X /= Area;
			Y /= Area * 2;
			
			X = 2 * n - X;
			
			db val_x = x * Area - X * Area;
			db val_y = y * Area - Y * Area;
			
			all.PB({{val_x, val_y}, mp[balance][s]});			
		}
		
		vector<db> all_x;
		for(auto i: all) all_x.PB(i.X.X);
		sort(ALL(all_x));
		vector<db> all_x_new;
		FOR(i, 0, SZ(all_x)){
			if (i == 0 || all_x[i] > all_x[i - 1] + EPS){
				all_x_new.PB(all_x[i]);
			}
		}
		
		all_x = all_x_new;
		const int Sz = SZ(all_x);
		vector<vector<pair<db, int>>> by_x(Sz);
		for(auto i: all){
			int id = lower_bound(ALL(all_x), i.X.X - EPS) - all_x.begin();
			by_x[id].PB({i.X.Y, i.Y});
		}
		
		FOR(i, 0, Sz) sort(ALL(by_x[i]));
		
		for(auto s: gen[balance]){
			db Area = area(s);
			db X = center_x(s);
			db Y = center_y(s);
			X /= Area;
			Y /= Area * 2;
						
			db val_x = X * Area - x * Area;
			db val_y = Y * Area - y * Area;
			
			auto it = lower_bound(ALL(all_x), val_x - EPS);
			if (it == all_x.end() || (*it) > val_x + EPS) continue;
			const vector<pair<db, int>>& vec = by_x[it - all_x.begin()];
			auto it2 = lower_bound(ALL(vec), MP(val_y - EPS, -1));
			if (it2 == vec.end() || (it2->X > val_y + EPS)) continue;
			
			int kinec = vec[it2 - vec.begin()].Y;
			string t = gen[balance][kinec];
			cout << s;
			reverse(ALL(t));
			for(auto& i: t) if (i == '(') i = ')';
			else i = '(';
			cout << t;
			cout << endl;
			return 0;
		}
	}
	
	assert(false);	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}