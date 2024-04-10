#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

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

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool solve(const set<PII>& s){
	if (SZ(s) == 0) return false;
	if (s.rbegin()->X < 4) return false;
	if (s.rbegin()->X >= 8) return true;
	if (SZ(s) == 1) return false;
	auto it = s.end();
	--it;
	--it;
	if (it->X >= 4) return true;
	if (it->X >= 2 && s.rbegin()->X >= 6) return true;
	if (it->X < 2) return false;
	if (it == s.begin()) return false;
	--it;	
	return it->X >= 2;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	const int m = 100000 + 47;
	set<PII> s;
	vector<int> cnt(m, 0);
	while(n--){
		int x; cin >> x;
		cnt[x]++;
	}
	FOR(x, 0, m) if (cnt[x]){
		s.insert({cnt[x], x});
	}

	int q; cin >> q;
	while(q--){
		char typ; cin >> typ;
		int x; cin >> x;
		if (typ == '+'){
			s.erase({cnt[x], x});
			cnt[x]++;
			s.insert({cnt[x], x});
		}else{
			s.erase({cnt[x], x});
			cnt[x]--;
			s.insert({cnt[x], x});
		}
		cout << (solve(s) ? "YES\n" : "NO\n");
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}