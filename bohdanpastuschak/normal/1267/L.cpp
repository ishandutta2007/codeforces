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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> solve(int n, int l, string s)
{
	vector<string> res(n);
	int from = 0;
	int ptr = 0;
	FOR(i, 0, l)
	{
		FOR(j, from, n) res[j] += s[ptr++];
		int new_from = from;
		RFOR(j, n, from) if (res[j].back() != res[n - 1].back())
		{
			new_from = j + 1;
			break;
		}
		
		FOR(j, from, new_from)
		{
			FOR(x, 0, l - i - 1)
			{
				res[j] += s.back();
				s.pop_back();
			}
		}
		from = new_from;
	}
	
	sort(ALL(res));	
	return res;
}

int n, l, k;
string s;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> l >> k >> s;
	sort(ALL(s));
	
	string t;
	FOR(i, 0, k * l) t += s[i];
	auto tut = solve(k, l, t);
	string curr;
	FOR(i, k * l, SZ(s)) 
	{
		curr += s[i];
		if (i % l == l - 1) 
		{
			tut.PB(curr);
			curr.clear();
		}		
	}
	
	assert(SZ(tut) == n);
	FOR(i, 0, SZ(tut))
		cout << tut[i] << endl;
		
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}