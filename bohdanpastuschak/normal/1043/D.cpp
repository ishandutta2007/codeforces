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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 1 << 17;
LL n, m;
VI a[10];
const LL mod = 1234567891;
int place[10][MAX];
LL h[10][MAX];
LL powers[MAX];

void precalc()
{
	powers[0] = 1;
	FOR(i, 1, MAX)
		powers[i] = powers[i - 1] * mod;
	
	FOR(i, 0, m)
	{
		LL M = 1;
		LL curr = 0;
		RFOR(j, n, 0)
		{
			curr += a[i][j] * M;
			h[i][j] = curr;
			M *= mod;
		}
	}
}

bool can(int from, int x)
{
	LL hash_treba = h[0][from] - h[0][from + x];
	hash_treba *= powers[from];
	
	int pershe = a[0][from];
	
	FOR(i, 1, m)
	{
		int T = place[i][pershe];
		LL hash_tut = h[i][T] - h[i][T + x];
		hash_tut *= powers[T];
		if (hash_tut != hash_treba)
			return 0;
	}
	
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, m)
		a[i].resize(n);
	
	FOR(i, 0, m)
		FOR(j, 0, n)
			cin >> a[i][j];
	
	precalc();
	LL ans = 0;
	FOR(i, 0, m)
		FOR(j, 0, n)
			place[i][a[i][j]] = j;
	
	FOR(i, 0, n)
	{
		int L = 1, R = n - i, M;
		while(R - L > 1)
		{
			M = (L + R) >> 1;
			if (can(i, M))
				L = M;
			else
				R = M;
		}
		
		if (can(i, R))
			M = R;
		else
			M = L;
		
		ans += M;
	}
	
	cout << ans << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}