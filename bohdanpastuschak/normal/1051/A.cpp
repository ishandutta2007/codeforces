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

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = SZ(s);
		int ans = 0;
		int ok1 = 0, ok2 = 0, ok3 = 0;
		
		FOR(i, 0, n)
		{
			if (s[i] >= '0' && s[i] <= '9')
				ok1++;
			else
				if (s[i] >= 'a' && s[i] <= 'z')
					ok2++;
				else
					if (s[i] >= 'A' && s[i] <= 'Z')
						ok3++;
		}
		
		ans = !ok1 + !ok2 + !ok3;
		if (ans == 1)
		{
			if (!ok1)
			{
				bool mali = ok2 >= ok3;
				FOR(i, 0, n)
					if (mali == (s[i] >= 'a' && s[i] <= 'z'))
					{
						s[i] = '0';
						break;
					}
			}
			else
			{
				if (!ok2)
				{
					bool mali = ok1 >= ok3;
					FOR(i, 0, n)
						if (mali == (s[i] >= '0' && s[i] <= '9'))
						{
							s[i] = 'a';
							break;
						}
				}
				else
				{
					bool mali = ok2 >= ok1;
					FOR(i, 0, n)
						if (mali == (s[i] >= 'a' && s[i] <= 'z'))
						{
							s[i] = 'A';
							break;
						}
				}
			}
		}
		else
		{
			if (ans == 2)
			{
				if (ok1)
				{
					s[1] = 'a';
					s[2] = 'A';
				}
				else
					if (ok2)
					{
						s[1] = '0';
						s[2] = 'A';
					}
					else
					{
						s[1] = '0';
						s[2] = 'a';
					}
			}
		}
		
		cout << s << endl;
	}
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}