#include <bits/stdc++.h>
using namespace std;

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
		int n;
		cin >> n;
		int m = n;
		map<int, int> mp;
		for(int i = 2; i * i <= n; ++i) 
			while(n % i == 0) n /= i, mp[i]++;
		if (n > 1) mp[n]++;
		n = m;
		VI p;
		for(auto i: mp) p.PB(i.X);
		
		if (SZ(p) >= 3)
		{
			cout << "YES\n";
			cout << p[0] << ' ' << p[1] << ' ' << n / (p[0] * p[1]) << endl;
			continue;
		}
		
		if (SZ(p) == 1)
		{
			int P = p[0];
			if (mp[P] >= 6)
			{
				cout << "YES\n";
				cout << P << ' ' << P * P << ' ' << n / (P * P * P) << endl;
				continue;
			}
		}
		
		if (SZ(p) == 2)
		{
			int x = p[0], y = p[1];
			if (mp[x] > 1 && mp[y] > 1)
			{
				cout << "YES\n";
				cout << x << ' ' << y << ' ' << n / (x * y) << endl;
				continue;
			}
			
			if (mp[x] + mp[y] >= 4)
			{
				cout << "YES\n";
				cout << x << ' ' << y << ' ' << n / (x * y) << endl;
				continue;
			}
		}
		
		cout << "NO\n";
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}