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
#define endl '\n'
const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
void bad()
{
	cout << ":(";
	exit(0);
}
  
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
 
	string t;
	cin >> t;
	int n = SZ(t);
	string beza;
	int cnt = 0;
	int last_a = -1;
	FOR(i, 0, n)
	{
		if (t[i] == 'a')
			last_a = i;
		else
			beza += t[i];
	}
	
	cnt = SZ(beza);
	if (cnt & 1)
		bad();
	
	FOR(i, 0, cnt >> 1)
		if (beza[i] != beza[i + cnt / 2])
			bad();
	
	string ans;
	int treba = cnt >> 1;
	FOR(i, 0, n)
	{
		ans += t[i];
		if (t[i] != 'a')
		{
			treba--;
			if (treba == 0)
			{
				FOR(j, i + 1, last_a + 1)
					if (t[j] != 'a')
						bad();
				FOR(j, i + 1, last_a + 1)
					ans += t[j];
				break;
			}
		}
	}
				
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}