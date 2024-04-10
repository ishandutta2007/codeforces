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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void bad()
{
	cout << "NO" << endl;
	exit(0);
}

const int N = 1 << 17;
int n;
int a[N];
map<int, int> mp;

void erase(int x)
{
	if (!mp.count(x))
		bad();
		
	mp[x]--;
	if (mp[x] == 0)
		mp.erase(x);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	if (n & 1)
		bad();
	
	int mn = INF;	
	FOR(i, 0, n)
	{
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	
	FOR(i, 0, n)
		a[i] -= mn;
		
	FOR(i, 0, n)
		mp[a[i]]++;
	
	if (mp[1] < 2)
		bad();
		
	erase(0);
	erase(1);
	erase(1);
	
	int last = 1;
	while(SZ(mp))
	{
		mn = mp.begin()->X;
		if (mn < last)
		{
			if (mn != last - 1)
				bad();
				
			if (mp[mn] >= 2)
			{
				erase(mn);
				erase(mn);
				last = mn;
				continue;
			}
			
			erase(mn);
			if (SZ(mp) == 0)
				break;
			erase(last);		
		}
		
		if (SZ(mp) == 0)
			break;
		
		erase(last + 1);
		if (SZ(mp) == 0)
			break;
		
		erase(last + 1);
		last++;
	}
	
	cout << "YES" << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}