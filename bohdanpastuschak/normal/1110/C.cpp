#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

int ANS[] = {0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int q;
	cin >> q;
	while(q--)
	{
		int a;
		cin >> a;
		if (a <= 10)
		{
			int ans = 0;
			FOR(i, 1, a)
				ans = max(ans, __gcd(a ^ i, a & i));
			cout << ans<< endl; 
			continue;
		}
		
		if (__builtin_popcount(a + 1) == 1)
		{
			int pos = 0;
			while(a != (1 << pos) - 1)
				++pos;
			
			cout << ANS[pos - 1] << endl;
			continue;
		}
		
		int bt = 1;
		while(a >= (1 << bt))
			++bt;
		cout << (1 << bt) - 1 << endl;
	}

	return 0;
}