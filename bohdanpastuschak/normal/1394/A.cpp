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

vector<LL> go(vector<int>& a){
	vector<LL> s(SZ(a), 0);
	FOR(i, 0, SZ(a)){
		s[i] = a[i];
		if (i) s[i] += s[i - 1];
	}

	return s;
}

inline LL get(vector<LL>& s, int l, int r){
	if (l > r) return 0;
	return s[r] - (l == 0 ? 0 : s[l - 1]);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, d, m;
	cin >> n >> d >> m;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i];
	vector<int> b, c;
	FOR(i, 0, n) if (a[i] <= m){
		b.PB(a[i]);
	}else c.PB(a[i]);
	
	LL ans = 0;
	sort(ALL(b));
	sort(ALL(c));
	reverse(ALL(b));
	reverse(ALL(c));

	auto sb = go(b);
	auto sc = go(c);
	
	for(int k = 0; ; ++k){		
		int she = n;
		if (k){
			she -= (k - 1) * (d + 1) + 1;
		}
		
		if (she < 0) break;		
		LL curr = get(sc, 0, min(SZ(c), k) - 1) + get(sb, 0, min(SZ(b), she) - 1);
		setmax(ans, curr);		
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}