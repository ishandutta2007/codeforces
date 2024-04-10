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

int solve(){
	string s; cin >> s;
	int n = SZ(s);
	VI cnt(10, 0);
	for(auto i: s) cnt[i - '0']++;
	int ans = *max_element(ALL(cnt));
	FOR(i, 0, 10) FOR(j, 0, 10) if (i != j){
		int tut = 0;
		bool lst = 0;
		for(auto x: s){
			if (lst == 0 && x == (char)('0' + i)){
				tut++;
				lst ^= 1;
			}else if (lst == 1 && x == (char)('0' + j)){
				tut++;
				lst ^= 1;
			}
		}
		
		setmax(ans, tut / 2 * 2);
	}
	
	return n - ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int tc; cin >> tc;
	while(tc--){
		//solve();
		cout << solve() << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}