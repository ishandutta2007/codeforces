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
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		bool was = false;
		FOR(i, 0, n) 
		{
			int x;
			cin >> x;
			was |= x == k;
			if (x == k) a[i] = 0;
			else if (x < k) a[i] = -1;
			else a[i] = +1;
		}
		
		if (!was){
			cout << "NO\n";
			continue;
		}
		
		was = false;
		if (n == 1) was = true;
		
		bool was0 = false;
		int cnt01 = 0;
		bool was11 = false;
		
		bool was_1 = false;
		int cnt_1 = 0;
		
		FOR(i, 0, n){
			if (a[i] == -1){
				was0 = false;
				cnt01 = 0;
				cnt_1++;
				continue;
			}
			
			if (cnt_1 == 1 && i != 1) was_1 = true;
			
			cnt_1 = 0;
			if (a[i] == 0){
				was0 = true;
				cnt01++;
				if (cnt01 > 1 && was0) was = true;
				continue;
			}
			
			cnt01++;
			if (cnt01 > 1 && was0) was = true;
			if (cnt01 > 1) was11 = true;
		}
		
		was |= was11;
		was |= was_1;
		
		cout << (was ? "YES\n" : "NO\n");
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}