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

const int N = 1 << 22;
LL n, k, a[N];

LL dataAdd[N], dataMul[N];

void internalUpdate(int at, int mul, int add) {
	while (at < N){
		dataMul[at] += mul;
		dataAdd[at] += add;
		at |= (at + 1);
	}
}

void update(int left, int right, int by) {
	setmin(right, N - 1);
	internalUpdate(left, by, -by * (left - 1));
	internalUpdate(right, -by, by * right);
}

LL query(int at){
	LL mul = 0;
	LL add = 0;
	LL start = at;
	while (at >= 0) {
		mul += dataMul[at];
		add += dataAdd[at];
		at = (at & (at + 1)) - 1;
	}
	return mul * start + add;
}

int check(){
	if (query(N - 1) < k) return INF;
	int l = 0, r = N - 1, m;
	while(r - l > 1){
		m = (l + r) >> 1;
		if (query(m) >= k) r = m;
		else l = m;
	}

	return r;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> k;
	FOR(i, 0, n) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	
	if (accumulate(a, a + n, 0LL) - 2 * n + 1 < k){
		cout << -1 << endl;
		return 0;
	}

	int ans = INF;
	int ptr = 0;
	update(0, 0, 1);
	
	FOR(i, 0, n){
		while (query(ptr) == 0) ptr++;
		update(ptr, ptr, -1);

		if (a[i] % 2 == 1){
			update(ptr + 2, ptr + a[i] / 2 + 1, 2);			
		}else{
			update(ptr + 2, ptr + a[i] / 2, 2);
			update(ptr + a[i] / 2 + 1, ptr + a[i] / 2 + 1, 1);
		}

		setmin(ans, check());
	}
	
	assert(ans < INF);
	cout << ans << endl;

	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}