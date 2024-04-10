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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		for(auto& i: s){
			if (i == 'W') i = 1;
			else i = 0;
		}

		int cnt = count(ALL(s), 1);
		if (cnt + k >= n){
			cout << 2 * n - 1 << '\n';
			continue;
		}

		int ans = cnt;
		s = "0" + s;
		FOR(i, 1, n + 1){
			ans += s[i] == 1 && s[i - 1] == 1;
		}

		if (ans == 0){
			cout << max(0, 2 * k - 1) << '\n';
			continue;
		}

		ans += 2 * k;
		vector<int> a;
		int len = 0;
		int was = 0;
		FOR(i, 1, n + 1){
			if (s[i] == 0){
				len++;
			}else{
				if (len && was) a.PB(len);
				was = 1;
				len = 0;
			}
		}

		sort(ALL(a));
		for(auto i: a){
			if (i <= k){
				ans++;
				k -= i;
			}else break;
		}
		
		cout << ans << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}