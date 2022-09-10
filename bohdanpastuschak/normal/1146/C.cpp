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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
vector<string> solve(int n)
{
	if (n == 2)
		return {"01"};

	auto s = solve(n >> 1);
	string str;
	vector<string> ans;
	FOR(i, 0, n >> 1)
		str += '0';
	FOR(i, 0, n >> 1)
		str += '1';
	ans.PB(str);
	for(auto i: s)
		ans.PB(i + i);	
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
 
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		auto ans = solve(128);
		
		for(auto& i: ans)	
			 i.resize(n);
		
		int A = 0;
		FOR(i, 0, SZ(ans))
		{
			VI v0, v1;
			FOR(j, 0, n)
				if (ans[i][j] == '0')
					v0.PB(j + 1);
				else
					v1.PB(j + 1);
			
			if (SZ(v0) == 0)
			{
				v0.PB(v1.back());
				v1.pop_back();
			}
			
			if (SZ(v1) == 0)
			{
				v1.PB(v0.back());
				v0.pop_back();
			}
			
			cout << SZ(v0) << ' ' << SZ(v1);
			for(auto j: v0)
				cout << ' ' << j;
			for(auto j: v1)
				cout << ' ' << j;
			cout << endl;
			fflush(stdout);
			int r;
			cin >> r;
			A = max(A, r);
		}
		
		cout << "-1 " << A << endl;
		fflush(stdout);		
	}
 
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}