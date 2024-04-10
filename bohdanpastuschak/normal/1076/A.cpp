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
const double E = 1e-5;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int n;
	string s;
	cin >> n >> s;
	
	FOR(i, 0, n - 1)
	{
		if (s[i] > s[i + 1])
		{
			FOR(j, 0, n)
				if (j != i)
					cout << s[j];
			return 0;
		}
		
		if (s[i] < s[i + 1])
			continue;
	
		int j = i + 1;
		while(j < n && s[i] == s[j])
			++j;
		
		if (j == n || s[i] > s[j])
		{
			FOR(k, 0, n)
				if (i != k)
					cout << s[k];
			return 0;
		}
		
		i = j - 1;
	}
	
	FOR(i, 0, n - 1)
		cout << s[i];

	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}