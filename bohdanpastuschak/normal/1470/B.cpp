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
int lp[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	iota(lp, lp + N, 0);
	FOR(i, 2, N) if (lp[i] == i) for(int j = i + i; j < N; j += i) setmin(lp[j], i);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> a;
		int em = 0;
		FOR(i, 0, n){
			int x; cin >> x;
			vector<int> tut;
			while(x > 1){
				int P = lp[x], C = 0;
				while(x % P == 0) x /= P, C ^= 1;
				if (C){
					tut.PB(P);
				}
			}

			a.PB(tut);
			em += SZ(tut) == 0;
		}

		int ans0 = 0, ans1 = 0;
		vector<int> sz;
		sort(ALL(a));
		int curr = 1;
		FOR(i, 1, SZ(a)){
			if (a[i] == a[i - 1]) curr++;
			else {
				sz.PB(curr);
				curr = 1;
			}
		}

		sz.PB(curr);

		ans0 = *max_element(ALL(sz));

		for(auto i: sz){
			if (i % 2 == 0){
				ans1 += i;
			}
		}

		if (em % 2 == 1){
			ans1 += em;
		}
		
		setmax(ans1, ans0);
		
		int q; cin >> q;
		while(q--){
			LL w; cin >> w;
			cout << (w == 0 ? ans0 : ans1) << '\n';
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}