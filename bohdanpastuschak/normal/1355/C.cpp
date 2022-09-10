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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	LL a, b, c, d;
	cin >> a >> b >> c >> d;
	LL ans = (b - a + 1) * (c - b + 1) * (d - c + 1);
	
	FOR(z, c, d + 1){
		//x + y <= z
		//a <= x <= b
		//b <= y <= c
		
		int treba = z - a - b;
		if (treba < 0){
			continue;
		}
		
		LL B = b - a, C = c - b;
		LL A = treba;
		//x + y <= A
		//x <= B
		//y <= C
		
		setmin(B, A);
		setmin(C, A);
		
		if (B + C <= A){
			ans -= (B + 1) * (C + 1);
			continue;
		}
		
		ans -= B + 1;
		ans -= (A - C + 1) * C;
		ans -= (B - (A - C + 1) + 1) * A;
		ans += B * (B + 1) / 2;
		ans -= (A - C) * (A - C + 1) / 2;
	}
	
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}