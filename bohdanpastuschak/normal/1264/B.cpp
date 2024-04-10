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

void bad()
{
	cout << "NO" << endl;
	exit(0);
}
VI cnt;

void check(vector<int> ans)
{
	map<int, int> C;
	for(auto i: ans) C[i]++;
	FOR(i, 0, 4) if (C[i] != cnt[i]) bad();
	FOR(i, 0, SZ(ans) - 1)
		if (abs(ans[i] - ans[i + 1]) != 1) bad();
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cnt.assign(4, 0);
	int sum = 0;
	FOR(i, 0, 4) cin >> cnt[i], sum += cnt[i];
	
	if (sum == 1)
	{
		cout << "YES" << endl;
		FOR(i, 0, 4) if (cnt[i]) cout << i << endl;
		return 0;
	}	
	
	if (cnt[0] + cnt[2] == 0) bad();
	
	if (cnt[0] > cnt[1] + 1) bad();
	if (cnt[0] == cnt[1] + 1)
	{
		if (cnt[2] || cnt[3]) bad();
		cout << "YES" << endl;
		cout << "0 ";
		FOR(i, 0, cnt[1]) cout << "1 0 ";
		cout << endl;
		return 0;
	}	
	
	if (cnt[3] > cnt[2] + 1) bad();
	
	if (cnt[3] == cnt[2] + 1)
	{
		if (cnt[0] || cnt[1]) bad();
		cout << "YES" << endl;
		cout << "3 ";
		FOR(i, 0, cnt[2]) cout << "2 3 ";
		cout << endl;
		return 0;
	}	
		
	/*if (abs(cnt[0] + cnt[2] - cnt[1] - cnt[3]) > 1) bad();
	if (cnt[0] > cnt[1] + 1) bad();
	if (cnt[3] > cnt[2] + 1) bad();
	
	//ifky
	
	if (cnt[0] > cnt[1]) bad();
	if (cnt[3] > cnt[2]) bad();*/
	
	vector<int> parni, neparni;
	FOR(i, 0, cnt[0]) parni.PB(0);
	FOR(i, 0, cnt[2]) parni.PB(2);
	
	FOR(i, 0, cnt[0]) neparni.PB(1);
	FOR(i, 0, cnt[3]) neparni.PB(3);
	
	while (SZ(neparni) < SZ(parni) - 1)
		neparni.PB(1);
	
	int she1 = cnt[1], she3 = cnt[3];
	for(auto i: neparni) if (i == 1) she1--; else she3--;
	
	bool persh1 = false;
	bool persh3 = false;
	if (she1)
	{
		she1--;
		persh1 = true;
	}	
	else if (parni[0] == 2 && she3)
	{
		she3--;
		persh3 = true;
	}		
	
	if (she1) she1--, neparni.PB(1);
	if (she3) she3--, neparni.PB(3);
	
	vector<int> ans;
	if (persh1)
		ans.PB(1);
	if (persh3)
		ans.PB(3);
	
	FOR(i, 0, SZ(parni))
	{
		ans.PB(parni[i]);
		if (i < SZ(neparni))
			ans.PB(neparni[i]);
	}
	
	check(ans);		
	cout << "YES" << endl;		
	for(auto i: ans) cout << i << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}