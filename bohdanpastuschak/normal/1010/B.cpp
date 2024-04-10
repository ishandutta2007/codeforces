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

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = 1e18;

int n, m;

int f(int x)
{
	cout << x << endl;
	fflush(stdout);
	cin >> x;
	return x;
}

char ok[100];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> m >> n;
	int reply = f(1);
	if (!reply)
		return 0;
	
	if (reply < 0)
		ok[0] = 0;
	else
		ok[0] = 1;
	
	FOR(i, 1, n)
	{
		reply = f(1);
		if (reply < 0)
			ok[i] = 0;
		else
			ok[i] = 1;
	}
	
	int L = 1, R = m + 1, M;
	FOR(i, 0, 60 - n)
	{
		M = (L + R) >> 1;
		reply = f(M);
		if (ok[i % n] == 0)
			reply *= -1;
		
		if (!reply)
			return 0;
		 
		if (reply > 0)
			L = M;
		else
			R = M;
	}
	
	assert(0);
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}