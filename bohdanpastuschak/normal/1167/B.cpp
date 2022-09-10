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

VI v = {4, 8, 15, 16, 23, 42};
	
int ask(int i, int j)
{
	cout << "? " << i << ' ' << j << endl;
	fflush(stdout);
	cin >> i;
	return i;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int x1 = ask(1, 2);
	int x2 = ask(3, 4);
	int x3 = ask(1, 3);
	int x4 = ask(2, 5);
	
	VI ans(6, 0);
	
	sort(ALL(v));
	vector<VI> can;
	do
	{
		bool ok = 1;
		ok &= v[0] * v[1] == x1;
		ok &= v[2] * v[3] == x2;
		ok &= v[0] * v[2] == x3;
		ok &= v[1] * v[4] == x4;
		
		if (!ok)
			continue;
		can.PB(v);		
	}while(next_permutation(ALL(v)));
	
	assert(SZ(can) == 1);
	ans = can[0];
	
	cout << "!";
	for(auto i: ans)
		cout << ' ' << i;
	cout << endl;
	fflush(stdout);

	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}