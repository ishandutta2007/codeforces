#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

namespace IntModulo
{
	const int mod = 1e9 + 7;

	inline int add(int x, int y, int m = mod)
	{
		if (x + y < m)
			return x + y;
		return x + y - m;
	}

	inline int sub(int x, int y, int m = mod)
	{
		if (x >= y)
			return x - y;
		return x - y + m;
	}

	inline int mult(int x, int y, int m = mod)
	{
		return x * (LL) y % m;
	}

	inline int power(int x, LL y, int m = mod)
	{
		int r = 1;
		while(y)
		{
			if (y & 1)
				r = mult(r, x, m);
			x = mult(x, x, m);
			y >>= 1;
		}
		
		return r;
	}
	
	inline int inverse(int x, int m = mod)
	{
		return power(x, m - 2, m);
	}

	inline void ADD(int& x, int y, int m = mod){
		x += y;
		if (x >= m) x -= m;
	}

	inline void SUB(int& x, int y, int m = mod){
		x -= y;
		if (x < 0) x += m;
	}

	inline void MULT(int& x, int y, int m = mod){
		x = (x * (LL) y) % m;
	}
};

using namespace IntModulo;
const int A = 60;
int a[A], b[A][A], c[A][A];
int je[A], neje[A], ptr1, ptr2;

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);//cin >> n;		
		
		FILL(a, 0);
		FILL(b, 0);
		FILL(c, 0);
		
		FOR(it, 0, n){
			LL x; scanf("%lld", &x);//cin >> x;
			ptr1 = ptr2 = 0;
			FOR(i, 0, A) if (x & (1LL << i)){
				a[i]++;
				je[ptr1++] = i;
			}else neje[ptr2++] = i;
			
			FOR(i, 0, ptr1) {
				const int& val = je[i];
				FOR(j, 0, ptr2){
					b[val][neje[j]]++;
				}

				FOR(j, 0, ptr1){
					c[val][je[j]]++;
				}
			}					
		}
		
		int ans = 0;
		FOR(i, 0, A) FOR(j, 0, A){
			int cnt = mult(a[i], add(mult(n, c[i][j]), mult(b[i][j], a[j])));
			ADD(ans, mult(cnt, power(2, i + j)));
		}

		cout << ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}