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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 10;
int n;
LL AREA[N];

int sign(int i, int j, int k)
{
	cout << "2 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	fflush(stdout);
	cin >> i;
	return i;
}

LL area(int i, int j, int k)
{
	cout << "1 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	fflush(stdout);
	LL res;
	cin >> res;
	return res;
}

int cmp1(int x, int y)
{
	return AREA[x] < AREA[y];
}

int cmp2(int x, int y)
{
	return AREA[x] > AREA[y];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	
	//1 ZNAJTY SUSIDA
	
	int kand = 1;
	FOR(i, 2, n)
	{
		if (sign(0, kand, i) == -1) continue;
		kand = i;
	}
	
	vector<pair<LL, int>> vec;
	FOR(i, 1, n) if (i != kand)
	{
		LL tut = area(0, kand, i);
		vec.PB({tut, i});
		AREA[i] = tut;
	}
	
	sort(ALL(vec));
	
	VI ans;
	
	//2 ZNAJTY NAJDALI
	
	int najdali = vec.back().Y;
	
	vector<int> zliva;
	vector<int> sprava;
	
	FOR(i, 1, n) if (i != kand && i != najdali)
	{
		if (sign(0, najdali, i) == 1) sprava.PB(i);
		else zliva.PB(i);
	}
	
	sort(ALL(zliva), cmp1);
	sort(ALL(sprava), cmp2);
	
	ans.PB(0);
	for(auto i: zliva) ans.PB(i);
	ans.PB(najdali);
	for(auto i: sprava) ans.PB(i);
	ans.PB(kand);
	
	cout << 0;
	for(auto i: ans) cout << ' ' << i + 1;
	cout << endl;
	fflush(stdout);
	
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}