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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
#define debug(a) cout << #a << " = " << a << endl;

const int N = 15e6 + 7;
const int MAX = 3e5 + 7;
int n;
int a[MAX];
int prime[N];
int cnt[N];

void precalc()
{
	FOR(i, 2, N)
		prime[i] = i;
	FOR(i, 2, N)
		if (prime[i] == i)
			for(LL j = i*(LL)i; j < N; j += i)
				if (prime[j] == j)
					prime[j] = i;
}

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	precalc();
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d", &a[i]);
	
	int g = a[0];
	FOR(i, 1, n)
		g = __gcd(g, a[i]);
	
	FOR(i, 0, n)
		a[i] /= g;
	
	FOR(i, 0, n)
	{
		int t = a[i];
		while(t > 1)
		{
			int Pr = prime[t];
			while(t % Pr == 0)
				t /= Pr;
			
			cnt[Pr]++;
		}
	}
	
	int ma = 0;
	FOR(i, 2, N)
		ma = max(ma, cnt[i]);
	
	if (ma == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	
	cout << n - ma << endl;	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}