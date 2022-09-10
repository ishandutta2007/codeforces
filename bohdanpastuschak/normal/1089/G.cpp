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
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

int a[7];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("In.txt" , "r" , stdin);
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		int sum = 0;
		FOR(i, 0, 7)
		{
			cin >> a[i];
			sum += a[i];
		}
		int ans = INF;
		int full = (k - 1) / sum;
		FOR(i, 0, 7)
		{
			int rem = k - sum * full;
			int curAns = 0;
			int pos = i;
			while(rem)
			{
				curAns++;
				rem -= a[pos++];
				if(pos == 7)
					pos = 0;
			}
			ans = min(ans, curAns);
		}
		cout << 7 * full + ans << "\n";
	}
	return 0;
}