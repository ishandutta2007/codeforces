#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 9;
int n;
LL a[N];

LL is2(LL x)
{
	LL s = sqrt(x);
	while(s * s < x)
		s++;
	while(s * s > x)
		s--;
	if (s * s == x)
		return s;
	return -1;
}

LL is3(LL x)
{
	LL s = pow(x, 1.0/3.0);
	while(s * s * s < x)
		s++;
	while(s * s * s > x)
		s--;
	if (s * s * s== x)
		return s;
	return -1;
}

LL is4(LL x)
{
	LL s = pow(x, 1.0/4.0);
	while(s * s * s * s < x)
		s++;
	while(s * s * s * s > x)
		s--;
	if (s * s * s * s == x)
		return s;
	return -1;
}

int mult(int x, int y)
{
	return x * (LL) y % 998244353;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	map<LL, int> mp;
	map<LL, int> hz;
	FOR(i, 0, n)
	{
		LL x = is4(a[i]);
		if (x != -1)
		{
			mp[x] += 4;
			continue;
		}
		
		x = is3(a[i]);
		if (x != -1)
		{
			mp[x] += 3;
			continue;
		}
		
		x = is2(a[i]);
		if (x != -1)
		{
			mp[x] += 2;
			continue;
		}
		
		hz[a[i]]++;
	}
	
	
	int ans = 1;
	for(auto it: hz)
	{
		LL i = it.X;
		bool ok = 0;
		FOR(j, 0, n)
		{
			LL g = __gcd(i, a[j]);
			if (g == 1)
				continue;
			
			if (g < i)
			{
				mp[g] += it.Y;
				mp[i / g] += it.Y;
				ok = 1;
				break;
			}
		}
		
		if (ok)
			continue;
		
		ans = mult(ans, (it.Y + 1) * (it.Y + 1));
	}
	
	for(auto i: mp)
		ans = mult(ans, i.Y + 1);
	cout << ans << endl;
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}