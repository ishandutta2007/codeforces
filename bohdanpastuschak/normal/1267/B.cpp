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

void zero()
{
	cout << 0;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	vector<pair<char, int> > v;
	int j;
	for(int i = 0; i < SZ(s); i = j)
	{
		j = i;
		while(j < SZ(s) && s[j] == s[i])
			j++;
		v.PB(MP(s[i], j - i));
	}
	if(SZ(v) % 2 == 0)
		zero();
	auto rev = v;
	reverse(ALL(rev));
	FOR(i, 0, SZ(v))
		if(v[i].first != rev[i].first || v[i].second + rev[i].second < 3)
			zero();
	cout << v[SZ(v) / 2].second + 1 << "\n";
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}