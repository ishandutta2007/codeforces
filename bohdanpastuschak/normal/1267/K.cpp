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

vector<int> go(LL x)
{
	vector<int> a;
	int curr = 2;
	while(x)
	{
		a.PB(x % curr);
		x /= curr;
		curr++;
	}
	
	sort(ALL(a));
	return a;
}

LL vidnowy(vector<int>& a)
{
	LL x = 0;
	RFOR(i, SZ(a), 0)
		x = x * (i + 2) + a[i];
	return x;	
}

inline void output(vector<int>& a)
{
	for(auto i: a) cout << i << ' ';
	cout << endl;
}

const int M = 20;

LL C[20][20];

LL f(vector<int> v)
{
	LL res = 1;
	FOR(i, 0, SZ(v))
		if(v[i] > i + 1)
			return 0;
	int j;
	for(int i = SZ(v) - 1; ; i = j)
	{
		j = i;
		while(j >= 0 && v[j] == v[i])
			j--;
		if(j < 0)
			break;
		res *= C[i + 2 - v[i]][i - j];
	}
	return res;
}

int brute(LL k)
{
	int br = 0;
	auto v = go(k);
		FOR(i, 1, 1000)
			if(go(i) == v)
				br++;
	return br;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	FOR(i, 0, M)
	{
		C[i][0] = 1;
		FOR(j, 1, i + 1)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	int t;
	cin >> t;
	while(t--)
	{
		LL k = t + 1;
		cin >> k;
		auto v = go(k);
		LL ans = f(v);
		//debug(ans)
		if(v[0] == 0)
		{
			reverse(ALL(v));
			v.pop_back();
			reverse(ALL(v));
			ans -= f(v);
		}
		cout << ans - 1 << "\n";
		//assert(ans == brute(k));
		//cout << endl;
	}
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}