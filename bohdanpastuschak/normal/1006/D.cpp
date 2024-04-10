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

int solve(char a1, char a2, char b1, char b2){
	map<char, int> S;
	S[a1]++;
	S[a2]++;
	S[b1]++;
	S[b2]++;

	if (SZ(S) == 1) return 0;
	if (SZ(S) == 2){
		if (S[a1] == 2 && S[a2] == 2 && S[b1] == 2) return 0;
	}
	if (a1 == a2 && b1 == b2) return 0;
	if (SZ(S) == 3 && a1 == a2) return 2;
	if (SZ(S) <= 3) return 1;
	return 2;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	string a, b;
	cin >> a >> b;

	int ans = 0;
	if (n & 1){
		if (a[n / 2] != b[n / 2]){
			ans++;
		}
	}

	FOR(i, 0, n / 2){
		ans += solve(a[i], a[n - 1 - i], b[i], b[n - 1 - i]);	
	}	
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}