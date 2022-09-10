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

void normalize(vector<int>& cnt, int to)
{
	FOR(i, 0, to)
	{
		int val = cnt[i] >> 1;
		cnt[i + 1] += val;
		cnt[i] -= val << 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		LL n, m;
		cin >> n >> m;
		vector<int> cnt(60, 0);
		LL sum = 0;
		while(m--)
		{
			int x;
			cin >> x;
			sum += x;
			int tut = 0;
			while(x) tut++, x >>= 1;
			tut--;
			cnt[tut]++;
		}
		
		if (n > sum)
		{
			cout << -1 << endl;
			continue;
		}
		
		int ans = 0;
		FOR(bit, 0, 60)
		{
			if (!(n & (1LL << bit))) continue;
			normalize(cnt, bit);
			if (cnt[bit])
			{
				cnt[bit]--;
				continue;
			}
			
			int tut = -1;
			FOR(i, bit + 1, 60) if (cnt[i])
			{
				tut = i;
				break;
			}
			
			//assert(tut != -1);
			while(tut > bit)
			{
				cnt[tut]--;
				tut--;
				cnt[tut] += 2;
				ans++;
			}
			
			cnt[bit]--;
		}
		
		cout << ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}