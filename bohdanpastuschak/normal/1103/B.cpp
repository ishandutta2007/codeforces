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
const LL INF = 1e9 - 47;
const LL LINF = INF * INF;

int cnt = 0;
map<PII, bool> asked;


bool ask(int x, int y)
{
	if (asked.count(MP(x, y)))
		return asked[MP(x, y)];
	
	++cnt;
	assert(cnt <= 60);
	cout << "? " << x << ' ' << y << endl;
	fflush(stdout);
	char rep;
	cin >> rep;
	
//	if (x % mod >= y % mod)
//		rep = 'x';
//	else
//		rep = 'y';
	
	if (rep == 'e')
		exit(0);
	
	return asked[MP(x, y)] = (rep == 'x');
}

int go(int N)
{
	if (ask(0, 1))
		return 1;
	
	int n = N;
	VI p;
	for(int i = 2; i * i <= N; ++i)
		if (N % i == 0)
		{
			while(N % i == 0)
				N /= i;
			p.PB(i);
		}
	
	if (N > 1)
		p.PB(N);
	
	N = n;
	if (SZ(p) == 0)
		return N;
	
	for(auto i: p)
	{
		while(N % i == 0)
		{
			int bude = N / i;
			if (ask(0, bude))
				N /= i;
			else
				break;
		}
	}
	
	return N;
}

string hackme = "weiufbgiebigbergjbrbrgbeugfiuewbufbwefyuewyffbyef   uyfbwfu wefyb 8hh7888t8fbwe yfg 87rg 87w4 gt86gwe7fyu weutgf wiuvfhjc afuecdbuiasvfncsuydvgfcusydjfgcbsh kjczzfhasiugh7e eyt 78eg8g ea78fhfiwauf kyasfksaghbfkucbhsbuifyhgabeigyjhewuyjgbjvnbe jhfgbusyjhgf i";

int Rand(int mod)
{
	return abs((rand() << 16) + rand() + SZ(hackme)) % mod;
}

int make_tle()
{
	int N = LINF;
	vector<LL> v;
	for(LL i = 1; i <= N; ++i)
		if (N % i == 0)
			v.PB(i);
	return SZ(v);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	srand(time(NULL));
	string s;
	while(cin >> s)
	{
		if (s == "end")
			return 0;
		
		asked.clear();
		cnt = 0;
		
		if (ask(0, 2))
		{
			int g = go(2);
			cout << "! " << g << endl;
			fflush(stdout);
			continue;
		}
		LL L, R;
		
		while(1)
		{
			L = Rand(INF);
			R = L + Rand(INF);
			if (L > R)
				swap(L, R);
			if (ask(L, R))
				break;
		}
		
		while(R - L > 1)
		{
			LL M = (L + R) / 2;
			bool ans = ask(L, M);
			if (ans)
				R = M;
			else
				L = M;
		}
	
		int N = -1;
		if (ask(0, L))
			N = L;
		else
			if (ask(0, R))
				N = R;
			else
			{
				int fuck = make_tle();
				cerr << fuck << endl;
			}
		
		int g = go(N);
		cout << "! " << g << endl;
		fflush(stdout);
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}