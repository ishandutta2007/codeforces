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

LL dam(LL a, LL b, LL c, LL d, LL t){
	LL B = 0;
	FOR(i, 1, t + 1){
		B += min(c, i * d);
	}
	return a * (t + 1) - b * B;
}

inline LL calc(LL A, LL B, LL t){
	return A * t * t + B * t;
}

inline LL get(LL A, LL B, LL k){
	//A * t * t + B * t -> min
	LL ans = LINF;
	
	if (k <= 10){
		FOR(t, 1, k){
			setmin(ans, A * t * t + B * t);
		}
	}else{
		setmin(ans, calc(A, B, 1));
		setmin(ans, calc(A, B, k - 1));
		LL val = -(B / (2 * A));

		int KK = 10;
		FOR(i, -KK, KK){
			LL V = val + i;
			if (1 <= V && V < k){
				setmin(ans, calc(A, B, V));
			}
		}
	}

	
	//cout << A << ' ' << B << ' ' << k << ' ' << ans << endl;
	return ans;
}

inline LL solver(LL a, LL b, LL c, LL d, LL k){
	LL A = 2 * a;
	LL B = b * d;
	//1 <= t < k
	//(t + 1) * (A - B* t) -> max

	return A - get(B, B - A, k);
}

inline LL solve(LL a, LL b, LL c, LL d){
	if (a > b * c){
		return -1;
	}
	if (d >= c){
		return a;
	}

	LL k = (c + d - 1) / d;
	//kd >= c
	
	LL ans = a;//t = 0
	setmax(ans, a + k * (a - b * c) + b * c * (k - 1) - b * d * k * (k - 1) / 2);//t >= k

	//1 <= t < k
	setmax(ans, solver(a, b, c, d, k) / 2);	
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << solve(a, b, c, d) << '\n';
	}	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}