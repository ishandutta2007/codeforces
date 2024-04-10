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

inline int compute(vector<int>& all, int sz){
	sort(ALL(all));
	all.resize(unique(ALL(all)) - all.begin());
	
	if (sz <= 20 && SZ(all) == (1 << sz)){
		return -1;
	}

	FOR(i, 0, SZ(all)) if (all[i] != i){
		return i;
	}

	return SZ(all);
}

const int N = 1 << 20;
int ptr, mas[N];

string solve(int n, int k, string& s){
	ptr = 0;

	int zeros = max(0, k - 20);
	const int sz = k - zeros;

	int ones = 0;	
	FOR(i, 0, n){
		if (ones >= zeros){
			if (i + sz <= n){
				int mask = 0;
				FOR(j, 0, sz){
					if (s[i + j] == '0'){
						mask |= 1 << (sz - 1 - j);
					}
				}
				
				mas[ptr++] = mask;
			}
		}
		
		if (s[i] == '1'){
			ones++;
		}else{
			ones = 0;
		}
	}

	vector<int> res(ptr);
	FOR(i, 0, ptr) res[i] = mas[i];
	int result = compute(res, sz);
	if (result == -1){
		return "";
	}

	string ans(k, '0');
	FOR(i, 0, 20) if (result & (1 << i)) ans[k - 1 - i] = '1';	
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		string res = solve(n, k, s);
		if (SZ(res) == 0){
			cout << "NO\n";
		}else{
			cout << "YES\n" << res << "\n";
		}
	}

	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}