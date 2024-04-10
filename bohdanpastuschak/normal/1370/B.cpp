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
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n + n);
		FOR(i, 0, n + n) cin >> a[i];
		vector<int> odd, even;
		FOR(i, 0, n + n) if (a[i] & 1) odd.PB(i);
		else even.PB(i);
		
		if (SZ(odd) & 1){
			odd.pop_back();
			even.pop_back();
		}else{
			if (SZ(odd) >= 2){
				odd.pop_back();
				odd.pop_back();
			}else{
				even.pop_back();
				even.pop_back();
			}
		}
		
		for(int i = 0; i < SZ(odd) - 1; i += 2){
			cout << odd[i] + 1 << ' ' << odd[i + 1] + 1 << endl;
		}
		for(int i = 0; i < SZ(even) - 1; i += 2){
			cout << even[i] + 1 << ' ' << even[i + 1] + 1 << endl;
		}
		//cout << endl;
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}