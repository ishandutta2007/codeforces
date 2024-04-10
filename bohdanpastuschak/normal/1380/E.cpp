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
int n, m;
set<int> S[N];
int where[N];
int bel[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	FILL(bel, -1);
	cin >> n >> m;
	FOR(i, 1, n + 1){
		int x;
		cin >> x;
		bel[i] = x;
		S[x].insert(i);
	}

	iota(where, where + N, 0);
	int ans = 0;
	FOR(i, 1, n) ans += bel[i] != bel[i + 1];
	cout << ans << '\n';
	FOR(it, 1, m){
		int a, b;
		cin >> a >> b;
		int sza = SZ(S[where[a]]);
		int szb = SZ(S[where[b]]);
		if (sza < szb) swap(a, b);		

		auto& s = S[where[a]];
		const auto& t = S[where[b]];
		for(auto el: t){
			if (bel[el - 1] == where[a] && bel[el + 1] == where[a]){
				ans -= 2;
			}else{
				if (bel[el - 1] == where[a] || bel[el + 1] == where[a]){
					ans -= 1;
				}
			}
		}
		
		for(auto el: t){
			s.insert(el);
			bel[el] = where[a];
		}
		
		where[b] = where[a];
		cout << ans << '\n';
	}
	
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}