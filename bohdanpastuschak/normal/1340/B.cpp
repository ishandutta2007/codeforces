#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> codes = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int decode(string s)
{
	int res = 0;
	for(auto i: s)
	{
		res += res;
		if (i == '1') res++;		
	}
	
	return res;
}

int f[1 << 7][1 << 7];
const int N = 1 << 11;
int A[10];
int n, k;
int s[N];
bool dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	FILL(f, -1);
	FOR(i, 0, 1 << 7) FOR(j, 0, 1 << 7)
		if ((i & j) == i)
			f[i][j] = __builtin_popcount(i ^ j);
	
	FOR(i, 0, 10) A[i] = decode(codes[i]);
	
	cin >> n >> k;
	FOR(i, 0, n) 
	{
		string S;
		cin >> S;
		s[i] = decode(S);
	}
	
	dp[n][0] = true;
	RFOR(i, n, 0) FOR(dig, 0, 10)
	{
		int cost = f[s[i]][A[dig]];
		if (cost == -1) continue;
		
		FOR(j, 0, N - 10)
			if (dp[i + 1][j])	
				dp[i][j + cost] = true;
	}
	
	if (!dp[0][k])
	{
		cout << -1 << endl;
		return 0;
	}
	
	string res(n, '0');
	FOR(i, 0, n) 
	{
		bool ok = false;
		RFOR(j, 10, 0)
		{
			int cost = f[s[i]][A[j]];
			if (cost == -1) continue;
			
			if (cost <= k && dp[i + 1][k - cost])
			{
				k -= cost;
				res[i] += j;
				ok = true;
				break;
			}
		}
		
		assert(ok);
	}
	
	assert(k == 0);
	cout << res << endl;	
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}