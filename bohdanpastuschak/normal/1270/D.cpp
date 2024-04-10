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

PII ask(vector<int>& a)
{
	cout << "?";
	for(auto i: a) cout << ' ' << i;
	cout << endl;
	fflush(stdout);
	int pos, a_pos;
	cin >> pos >> a_pos;
	return {pos, a_pos};
}

void answer(int m)
{
	cout << "! " << m << endl;
	fflush(stdout);
	exit(0);
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	if (k == 1) answer(1);
	
	vector<int> a(k);
	iota(ALL(a), 1);
	
	PII res = ask(a);	
	int cnt_less = 0;
	vector<int> b;
	FOR(i, 1, k + 2) if (i != res.X) b.PB(i);
	PII res2 = ask(b);	
	bool nxt_is_bigger = res2.Y > res.Y;
	
	FOR(i, 1, k + 1)
	{
		if (i == res.X) continue;
		
		vector<int> tut;
		FOR(j, 1, k + 2) if (j != i) tut.PB(j);
		PII R = ask(tut);
		
		if (nxt_is_bigger)
		{
			if (R.Y != res.Y) 
				cnt_less++;
		}
		else
		{
			if (R.Y == res.Y)
				cnt_less++;
		}
	}	
	
	answer(cnt_less + 1);
	return 0;
}