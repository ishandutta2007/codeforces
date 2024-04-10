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
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

int n, k, p;
int a[1 << 17];

void bad()
{
	cout << "NO" << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> k >> p;
	FOR(i, 0, n)
		cin >> a[i];
	
	vector<VI> ans;
	int sum = 0;
	FOR(i, 0, n)
		sum ^= a[i] & 1;
	
	if ((k - p) % 2 != sum)
		bad();
	
	VI odd, even;
	FOR(i, 0, n)
		if (a[i] & 1)
			odd.PB(a[i]);
		else
			even.PB(a[i]);
	
	int treba_odd = k - p;
	if (SZ(odd) < treba_odd)
		bad();
	
	VI vec;
	for(auto i: odd)
	{
		if (treba_odd)
		{
			treba_odd--;
			ans.PB(VI(1, i));
		}
		else
		{
			vec.PB(i);
		}
	}

	for(auto i: even)
		vec.PB(i);

	if (!p)
	{
		vec.PB(ans.back()[0]);
		ans.pop_back();
		ans.PB(vec);
		goto suka;
	}
	
	
	
	while(SZ(ans) < k - 1)
	{
		if (SZ(vec) == 0)
			bad();
		
		if (vec.back() & 1)
		{
			if (SZ(vec) == 1)
				bad();
	
			VI vv;
			vv.PB(vec.back());
			vec.pop_back();
			vv.PB(vec.back());
			vec.pop_back();
			ans.PB(vv);
		}
		else
		{
			ans.PB(VI(1, vec.back()));
			vec.pop_back();
		}
	}
	
	if (SZ(ans) < k && SZ(vec) == 0)
		bad();
	else
		if (SZ(ans) < k)
			ans.PB(vec);
	
	suka:
	cout << "YES" << endl;
	for(auto i: ans)
	{
		cout << SZ(i);
		for(auto j: i)
			cout << ' ' << j;
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}