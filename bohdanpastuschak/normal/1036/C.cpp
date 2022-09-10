#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 23;
int ptr;
LL all[N];
LL pw[19];

void solve()
{
	LL l, r;
	cin >> l >> r;
	int ans = upper_bound(all, all + ptr, r) - lower_bound(all, all + ptr, l);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	pw[0] = 1;
	FOR(i, 1, 19)
		pw[i] = pw[i - 1] * 10;
		
	all[ptr++] = pw[18];
	FOR(i, 0, 18)
		FOR(j, 1, 10)
			all[ptr++] = pw[i] * j;
			
	FOR(i, 0, 18)
		FOR(j, i + 1, 18)
			FOR(k, 1, 10)
				FOR(l, 1, 10)
					all[ptr++] = pw[i] * k + pw[j] * l;
	FOR(i, 0, 18)
		FOR(j, i + 1, 18)
			FOR(k, j + 1, 18)
				FOR(ki, 1, 10)
					FOR(kj, 1, 10)
						FOR(kk, 1, 10)
							all[ptr++] = pw[i] * ki + pw[j] * kj + pw[k] * kk;
	
	sort(all, all + ptr);
	int q;
	cin >> q;
	while(q--)
		solve();
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}