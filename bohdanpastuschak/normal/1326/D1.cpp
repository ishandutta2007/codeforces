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

const int N = 1 << 20;
int d1[N];
int d2[N];

void go(string& s)
{
	int n = SZ(s);
	FOR(i, 0, n) d1[i] = d2[i] = 0;
	
	int l=0, r=-1, k, i;
	for(i = 0; i < n; i++){
	if(i > r) k = 1;
	else k = min(d1[l + r - i], r - i);

	while(0 <= i-k && i+k < n && s[i - k] == s[i + k]) k++;
	d1[i] = k;
	if(i + k - 1 > r)
	r = i + k - 1, l = i - k + 1;
	}
	
	l = 0, r = -1;
	for(i = 0; i < n; i++){
	if(i > r) k = 0;
	else k = min(d2[l + r - i + 1], r - i + 1);

	while(i + k < n && i - k - 1 >= 0 && s[i+k] == s[i - k - 1]) k++;
	d2[i] = k;

	if(i + k - 1 > r)
	l = i - k, r = i + k - 1;
	}
}

inline bool is(string& s)
{
	FOR(i, 0, SZ(s) / 2) 
		if (s[i] != s[SZ(s) - 1 - i])
			return false;
	return true;
}

int solve(string t)
{
	//debug(t)
	//go(t);
	int ans = 0;
	int sz = SZ(t);
	FOR(i, 0, sz)
	{
		bool ok = 1;
		for(int j = 0; ok && j <= i; ++j)
			ok &= t[j] == t[i - j];
			
		if (ok) ans = i + 1;
	}
	
	assert(ans < sz);
	//debug(ans)
	return ans;
}

void solve()
{
	string s;
	cin >> s;
	if (is(s))
	{
		cout << s << endl;
		return;
	}
	
	int n = SZ(s);
	
	int l = 0, r = n - 1;
	while(l < r && s[l] == s[r])
		l++, r--;
	
	string t;
	FOR(i, l, r + 1) t += s[i];
	
	int livo = solve(t);
	reverse(ALL(t));
	int pravo = solve(t);
	
	if (livo > pravo) l += livo;
	else r -= pravo;
		
	string ans;
	FOR(i, 0, l) ans += s[i];
	FOR(i, r + 1, n) ans += s[i];
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}