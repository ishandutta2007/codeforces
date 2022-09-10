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

int brute(int n, string s, vector<int>& ok){
	int ans = 0;
	while(true){
		string curr;
		FOR(i, 0, n - 1) if (!ok[s[i + 1]]) curr += s[i];
		curr += s.back();
		if (SZ(curr) == n) break;
		ans++;
		s = curr;
		n = SZ(s);
	}
	
	return ans;
}

int solve(int n, string s, vector<int>& ok){
	int ans = -1;
	RFOR(i, n, 0) if (ok[s[i]]){
		ans = i; break;
	}
	
	if (ans <= 0){
		return 0;
	}
	
	n = ans;
	vector<int> dp(n, 0);
	RFOR(i, n, 0){
		if (ok[s[i + 1]]){
			dp[i] = 1;
		}else{
			dp[i] = 1 + dp[i + 1];
		}
	}
	
	return *max_element(ALL(dp));
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	
 	int t; cin >> t;
 	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		for(auto& i: s) i -= 'a';
		int k; cin >> k;
		vector<int> ok(26, 0);
		while(k--){
			char x; cin >> x;
			ok[x - 'a'] = 1;
		}
		
		//int B = brute(n, s, ok);
		int S = solve(n, s, ok);
		cout << S << endl;
		//if (B == S) continue;
		//if (B != S) cout << B << ' ' << S << endl;
		
		//return 0;
	}
	
 	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}