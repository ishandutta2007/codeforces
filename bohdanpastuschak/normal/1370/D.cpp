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

const int N = 1 << 20;
int n, k;
int a[N];
int b[N];

bool ok(int x){
	FOR(i, 0, n) b[i] = a[i] <= x;
	
	int cnt;
	cnt = 0;
	bool odd_now = true;
	FOR(i, 0, n){
		if (odd_now){
			if (b[i]){
				cnt++;
				odd_now = false;
			}
		}else{
			cnt++;
			odd_now = true;
		}
	}
	
	if (cnt >= k) return true;
	cnt = 0;
	odd_now = true;
	FOR(i, 0, n){
		if (odd_now){
			cnt++;
			odd_now = false;
		}else{
			if (b[i]){
				cnt++;
				odd_now = true;
			}
		}
	}
	
	if (cnt >= k) return true;	
	return false;	
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> k;
	FOR(i, 0, n) cin >> a[i];
	
	int l = 0, r = INF, m;
	while(r - l > 1){
		m = (l + r) >> 1;
		if (ok(m)) r = m;
		else l = m;
	}
	
	cout << r << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}