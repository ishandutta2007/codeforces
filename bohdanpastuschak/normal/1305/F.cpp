#include <bits/stdc++.h>
using namespace std;

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
int n;
LL a[N];
int p[N];
vector<int> primes;

inline LL get_rem(LL x, LL P)
{
	if (x < P) return P - x;
	LL rem = x % P;
	return min(rem, P - rem);
}

inline void update_prime(LL P, LL& ans)
{
	LL zara = 0;
	FOR(i, 0, n)
	{
		zara += get_rem(a[i], P);
		if (zara > ans) return;
	}
	
	ans = zara;
}

inline bool CL()
{
	return clock() / (double) CLOCKS_PER_SEC >= 1.8;
}

const int MAGIC = 100;

inline void update(int id, LL& ans)
{
	LL from = max(1LL, a[id] - MAGIC);
	LL to = a[id] + MAGIC;
	
	set<LL> Primes;
	for(LL i = from; i <= to; ++i)
	{
		LL x = i;
		for(auto j: primes)
		{
			if (j * (LL) j > x) break;
			if (x % j) continue;
			Primes.insert(j);
			while(x % j == 0) x /= j;
		}
		
		if (x > 1) Primes.insert(x);
	}
	
	for(auto i: Primes) 
		update_prime(i, ans);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	iota(p + 2, p + N, 2);
	FOR(i, 2, N) if (p[i] == i)
	{
		primes.PB(i);
		for(int j = i + i; j < N; j += i)
			if (p[j] == j)
				p[j] = i;
	}
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	
	LL ans = n;
	update_prime(2, ans);
	
	while(!CL())
	{
		int id = rng() % n;
		update(id, ans);
	}	
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}