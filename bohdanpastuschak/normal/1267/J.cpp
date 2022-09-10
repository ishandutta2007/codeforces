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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 21;
int n;
int cnt[N];

int main()
{	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		FOR(i, 0, n) cnt[i] = 0;
		FOR(i, 0, n) 
		{
			int x;
			scanf("%d", &x);
			cnt[x - 1]++;
		}
		
		sort(cnt, cnt + n);
		int ptr = 0;
		while(cnt[ptr] == 0) ptr++;
		vector<PII> a;
		a.PB({cnt[ptr], 1});
		FOR(i, ptr + 1, n) if (cnt[i] == cnt[i - 1]) a.back().Y++;
		else a.PB({cnt[i], 1});
		
		int ans = n;
		int mn = cnt[ptr];
		FOR(s, 2, mn + 2)
		{
			bool ok = true;
			int tut = 0;
			for(auto i: a)
			{
				int x = 0, y = 0;
				y = ((-i.X % s) + s) % s;
				x = (i.X - y * (s - 1)) / s;				
				if (i.X < y * (s - 1))
					ok = false;
				else
					tut += (x + y) * i.Y;
			}
			
			if (ok) ans = min(ans, tut);
		}
				
		cout << ans << '\n';
	}	
	
	return 0;
}