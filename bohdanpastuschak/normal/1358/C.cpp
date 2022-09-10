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
const LL INF = 1e9;
const LL LINF = INF * INF;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  	
  	int t;
  	cin >> t;
  	while(t--){
  		int x1, x2, y1, y2;
  		cin >> x1 >> y1 >> x2 >> y2;
  		int dx = x2 - x1;
  		int dy = y2 - y1;
  		if (dx > dy) swap(dx, dy);
  		LL ans = dx * (LL) dy;  		
  		cout << ans + 1 << endl;
  	}
  	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}