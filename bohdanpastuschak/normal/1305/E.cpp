#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 5e8 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	
	int n, m;
	cin >> n >> m;
	if (m > (n - 1) * (n - 1) / 4)
	{
		cout << -1 << endl;
		return 0;
	}
	
	int k = 1;
	while(m > (k - 1) * (k - 1) / 4) k++;
	//m <= (k - 1) * (k - 1) / 4
	assert(k <= n);
	
	vector<int> a(k - 1);
	iota(ALL(a), 1);
	m -= (k - 2) * (k - 2) / 4;
	
	int NN = 2 * n + 47474;
	vector<int> C(NN, 0);
	FOR(i, 0, SZ(a)) FOR(j, i + 1, SZ(a))
		C[a[i] + a[j]]++;
	
	bool ok = false;
	FOR(i, k, SZ(C)) if (C[i] == m)
	{
		a.PB(i);
		ok = true;
		break;
	}
	
	assert(ok == true);
	
	const int LOL = 5e8 + 47;
	const int N = 50000;
	FOR(i, 0, n - k)
		a.PB(LOL + i * N);
		
	for(auto i: a) cout << i << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}