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
const LL INF = 1e9;
const LL LINF = 1e18;
const int MAX = 2e5 + 47;

int n;
map<string, set<string>> mp;

vector<string> normalize(set<string> a)
{
	vector<string> res;
	ITER(it, a)
	{
		bool ok = 0;
		string s = *it;
		ITER(it2, a)
		{
			if (*it2 == s)
				continue;

			string t = *it2;
			if (SZ(t) < SZ(s))
				continue;

			bool tut = 1;
			//cout << s << " " << t << endl;
			FOR(i, SZ(t) - SZ(s), SZ(t))
				if (t[i] != s[i - SZ(t) + SZ(s)])
					tut = 0;

			ok |= tut;
		}

		if (!ok)
			res.PB(s);
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	string s;
	int k;
	string t;
	FOR(i, 0, n)
	{
		cin >> s;
		cin >> k;
		FOR(j, 0, k)
		{
			cin >> t;
			mp[s].insert(t);
		}
	}

	cout << SZ(mp) << endl;
	ITER(it, mp)
	{
		cout << it->X;
		vector<string> vec = normalize(it->Y);
		cout << " " << SZ(vec);
		FOR(i, 0, SZ(vec))
			cout << " " << vec[i];
		cout << endl;
	}

	return 0;
}