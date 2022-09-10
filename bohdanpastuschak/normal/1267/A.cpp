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
const LL LINF = 2 * INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 1 << 18;

LL a[MAX], b[MAX], t[MAX];
int idx[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	set<pair<LL, int> > s1, s2;//s1 - 
	FOR(i, 0, n)
	{
		cin >> a[i] >> b[i] >> t[i];
		idx[i] = i;
		s2.insert(MP(a[i] + t[i], i));
	}
	sort(idx, idx + n, [](int i, int j){return a[i] < a[j];});
	int ptr = 0;
	LL T = 0;
	LL ans = 0;
	while(true)
	{
		while(ptr < n && a[idx[ptr]] <= T)
		{
			s2.erase(MP(a[idx[ptr]] + t[idx[ptr]], idx[ptr]));
			s1.insert(MP(t[idx[ptr]], idx[ptr]));
			ptr++;
		}
		while(!s1.empty())
		{
			int i = s1.begin()->second;
			if(T + t[i] > b[i])
				s1.erase(s1.begin());
			else
				break;
		}
		if(s1.empty() && s2.empty())
			break;
		int bestI = -1;
		LL best = LINF;
		if(!s1.empty())
		{
			best = T + s1.begin()->first;
			bestI = s1.begin()->second;
		}
		if(!s2.empty() && s2.begin()->first < best)
		{
			best = s2.begin()->first;
			bestI = s2.begin()->second;
			T = a[bestI];
		}
		assert(bestI != -1);
		LL end = b[bestI];
		//debug(ptr)
		if(ptr < n)
			end = min(end, a[idx[ptr]]);
		LL k = max(1LL, (end - T) / t[bestI]);
		T += k * t[bestI];
		ans += k;
		/*debug(bestI)
		debug(k)
		debug(T)
		cout << endl;*/
	}
	cout << ans << "\n";
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}