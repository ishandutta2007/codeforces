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

const int N = 1 << 18;
int n;
int a[N];

void go(vector<int>& x){
	int sz = SZ(x);
	vector<int> p(sz);
	iota(ALL(p), 0);
	while(true){
		shuffle(ALL(p), rng);
		bool ok = 1;
		FOR(i, 0, sz) ok &= p[i] != i;
		if (ok) break;
	}

	vector<int> y(sz);
	FOR(i, 0, sz) y[i] = x[p[i]];
	x = y;
}

int check(vector<int>& b){
	int cnt = 0;
	int len = 0;
	FOR(i, 0, SZ(b)){
		if (b[i] == i){
			cnt += len > 0;
			len = 0;
		}else{
			len++;
		}
	}

	cnt += len > 0;
	return cnt;
}

int solve(){
	cin >> n;
	FOR(i, 0, n) cin >> a[i], a[i]--;
	while(false){
		vector<int> b(n);
		FOR(i, 0, n) cin >> b[i];
		int l = rng() % n;
		int r = rng() % n;
		if (l > r) swap(l, r);
		if (l == r) continue;
		vector<int> lol;
		FOR(i, l, r + 1) lol.PB(b[i]);
		go(lol);
		FOR(i, l, r + 1) b[i] = lol[i - l];
		if (check(b) <= 1){
			cout << "SUCCESS" << endl;
			FOR(i, 0, n) cout << b[i] << ' ';
			cout << endl;
			exit(0);
		}
	}

	vector<int> b(n);
	FOR(i, 0, n) b[i] = a[i];
	return min(2, check(b));
	
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc = 1;
	cin >> tc;
	while(tc--){
		//solve();
		cout << solve() << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}