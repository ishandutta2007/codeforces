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
int n, m, x, y, k;
int a[N];
int b[N];
int pos[N];
bool tut[N];

void bad(){
	cout << -1 << endl;
	exit(0);
}

LL check(int l, int r, int mx){
	if (l > r) return 0;
	int lft = -1;
	FOR(i, l, r + 1) if (a[i] > mx){
		if (lft == -1) lft = i;
	}

	const int len = r - l + 1;
	if (lft == -1){
		LL raz = y * (LL) len;
		LL dwa = x * (LL) (len / k) + y * (LL) (len % k);
		return min(raz, dwa);
	}

	if (len < k) bad();
	LL raz = y * (LL) (len - k) + x;
	LL dwa = x * (LL) (len / k) + y * (LL) (len % k);
	return min(raz, dwa);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m >> x >> k >> y;
	FOR(i, 0, n) cin >> a[i + 1];
	FOR(i, 0, m) cin >> b[i + 1];
	FILL(pos, -1);
	FOR(i, 1, n + 1){
		pos[a[i]] = i;
	}

	int lst = -1;
	FOR(i, 1, m + 1){
		if (pos[b[i]] == -1) bad();
		if (pos[b[i]] < lst) bad();
		lst = pos[b[i]];
		tut[pos[b[i]]] = true;
	}

	LL ans = 0;
	a[0] = b[0] = -1;
	a[n + 1] = b[m + 1] = -1;
	tut[0] = tut[n + 1] = true;

	lst = 0;
	FOR(i, 1, n + 2){
		if (tut[i]){
			ans += check(lst + 1, i - 1, max(a[lst], a[i]));
			lst = i;
		}
	}	

	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}