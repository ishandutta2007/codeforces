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

const int MAX = 100 + 7;
int n;
int a[MAX];
int cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	int od = 0, tr = 0;
	FOR(i, 1, MAX)
		if (cnt[i] == 1)
			od++;
		else
			if (cnt[i] > 2)
				tr++;
	
	if ((od & 1) && tr == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	bool treba = 0;
	if (od & 1)
		treba = 1;
	
	int balance = 0;
	FOR(i, 0, n)
	{
		if (cnt[a[i]] == 1)
		{
			if (balance == 0)
				cout << "A";
			else
				cout << "B";
			
			balance ^= 1;
			continue;
		}
		
		if (cnt[a[i]] == 2 || !treba)
		{
			cout << "A";
			continue;
		}
		
		if (treba)
		{
			cout << "B";
			treba = 0;
		}		
	}	
	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}