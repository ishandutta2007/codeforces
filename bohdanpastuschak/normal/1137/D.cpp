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

const int N = 10;
int d[N];
int t = -1;
int c = -1;

vector<string> ask(VI go)
{
	cout << "next";
	for(auto i: go)
	{
		d[i]++;
		cout <<' ' << i;
	}
	
	cout << endl;
	fflush(stdout);
	int n;
	cin >> n;
	vector<string> ans(n);
	FOR(i, 0, n)
		cin >> ans[i];
	return ans;
}

void done()
{
	cout << "done" << endl;
	fflush(stdout);
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	VI vec;
	FOR(i, 0, 10)
		vec.PB(i);

	bool oboje = 1;
	int iteration = 1;
	while(1)
	{
		vector<string> res;
		if (oboje)
			res = ask({0, 1});
		else
			res = ask({0});
		
		if (SZ(res) == 2 && !oboje)
		{
			assert(res[0] == "01" || res[1] == "01");
			break;
		}
		
		oboje ^= 1;
		++iteration;
	}
	
	while(1)
	{
		vector<string> res = ask({0});
		if (SZ(res) == 2)
			break;
	}
	
	while(1)
	{
		vector<string> res = ask(vec);
		if (SZ(res) == 1)
			break;
	}
	
	done();	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}