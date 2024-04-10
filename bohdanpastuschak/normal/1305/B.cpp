#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	
	string s;
	cin >> s;
	
	bool ok = false;
	bool was = 0;
	for(auto i: s)
	{
		if (i == '(') was = 1;
		else ok |= was;
	}
	
	if (!ok)
	{
		cout << 0 << endl;
		return 0;
	}
	
	cout << 1 << endl;
	vector<int> ans;
	
	int open = 0, close = 0;
	for(auto i: s) 
		close += i == ')';
	
	FOR(i, 0, SZ(s))
	{
		if (s[i] == '(')
			open++;
		else
			close--;
		
		if (open == close)
		{
			FOR(j, 0, i + 1) 
				if (s[j] == '(') ans.PB(j);
			FOR(j, i + 1, SZ(s))
				if (s[j] == ')') ans.PB(j);
			break;
		}
	}		
	
	assert(SZ(ans) > 0);
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i + 1 << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}