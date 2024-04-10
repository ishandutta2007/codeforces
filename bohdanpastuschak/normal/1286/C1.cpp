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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cmp(string l, string r)
{
	if (SZ(l) != SZ(r)) return SZ(l) < SZ(r);
	FOR(i, 0, SZ(l)) if (l[i] != r[i]) return l[i] < r[i];
	return false;
}

bool local = false;
string guess;

vector<string> ask(int l, int r)
{
	int len = r - l + 1;
	vector<string> res(len * (len + 1) / 2);
	
	if (local)
	{
		--l;
		--r;
		res.clear();
		FOR(i, l, r + 1) 
		{
			string tut;
			FOR(j, i, r + 1)
			{
				tut += guess[j];
				random_shuffle(ALL(tut));
				res.PB(tut);
			}
		}
		
		random_shuffle(ALL(res));
	}
	else
	{
		cout << "? " << l << ' ' << r << endl;
		fflush(stdout);	
		for(auto& i: res) cin >> i;
	}

	for(auto& i: res) sort(ALL(i));
	sort(ALL(res), cmp);
	return res;
}

void answer(string& s)
{
	if (local)
	{
		assert(s == guess);
		exit(0);
	}
	
	cout << "! " << s << endl;
	fflush(stdout);
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	if (local) cin >> guess;
	
	int n;
	cin >> n;
	auto all = ask(1, n);
	if (n == 1)
		answer(all[0]);
	
	auto bez = ask(1, n - 1);
	string ans(n, 0);
	map<char, int> cnt;
	string vje;
	for(auto i: all) if (SZ(i) == 1) cnt[i[0]]++;
	for(auto i: bez) if (SZ(i) == 1) cnt[i[0]]--;
	for(auto i: cnt) if (i.Y) vje += i.X;
	
	assert(SZ(vje) == 1);
		
	map<string, int> cnt_bez, cnt_all;
	for(auto i: all) cnt_all[i]++;
	for(auto i: bez) cnt_bez[i]++;
	
	vector<string> diff;
	for(auto i: cnt_all)
	{
		if (cnt_bez[i.X] == i.Y) continue;
		assert(i.Y == cnt_bez[i.X] + 1);
		diff.PB(i.X);
	}
	
	assert(SZ(diff) == n);
	sort(ALL(diff), cmp);
	
	map<char, int> in_vje;
	in_vje[vje[0]]++;
	
	FOR(i, 2, n + 1)
	{
		auto tut = diff[i - 1];
		assert(SZ(tut) == i);
		
		map<char, int> T;
		for(auto j: tut) T[j]++;
		int CNT = 0;
		for(auto j: T) if (j.Y > in_vje[j.X])
		{
			CNT++;
			vje += j.X;
			in_vje[j.X]++;
		}
		
		assert(CNT == 1);
	}
	
	reverse(ALL(vje));
	answer(vje);
	
	return 0;
}