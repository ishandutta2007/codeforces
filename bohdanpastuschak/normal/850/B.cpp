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

const int N = 1 << 20;
int n, x, y;
int lp[N];
int a[N];
vector<int> primes;
int cnt[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> x >> y;
	iota(lp, lp + N, 0);
	FOR(i, 2, N) if (lp[i] == i){
		for(int j = i + i; j < N; j += i) setmin(lp[j], i);
		primes.PB(i);
	}

	FOR(i, 0, n){
		cin >> a[i];
	}

	if (n == 1){
		if (a[0] == 1) cout << min(x, y);
		else cout << 0;
		cout << endl;
		return 0;
	}
	
	LL ans = 0;
	FOR(i, 0, n) if (a[i] & 1){
		ans += min(x, y);
	}

	FOR(i, 0, n){
		int t = a[i];
		while(t > 1){
			int P = lp[t];
			while(t % P == 0) t /= P;
			cnt[P]++;
		}
	}

	int mx = 0;
	FOR(i, 0, N) setmax(mx, cnt[i]);
	setmin(ans, (n - mx) * (LL) x);	

	int magic = n / 20 - 10;
	FOR(p, 2, N) if (cnt[p] >= magic){
		LL curr = 0;
		FOR(i, 0, n) if (a[i] % p){
			int tut = p - (a[i] % p);
			curr += min((LL)x, tut * (LL) y);
		}
		
		setmin(ans, curr);
	}
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}