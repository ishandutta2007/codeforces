#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 2e5 + 47;
int N , k , p;
int dpT[20001][51][101];
int A[20001];
int dp(int idx , int blocks , int byMod)
{
	if(blocks == k)
	{
		return -INF;
	}
	if(idx == N)
	{
		if(blocks == k - 1)
		{
			return byMod;
		}
		else
			return -INF;
	}
	if(dpT[idx][blocks][byMod] != -1)
		return dpT[idx][blocks][byMod];
	int ans = dp(idx + 1 , blocks , (byMod + A[idx]) % p);
	
	ans = max(ans , byMod + dp(idx + 1 , blocks + 1 , A[idx]));
	
	
	
	return dpT[idx][blocks][byMod] = ans;
}
int main()
{
	memset(dpT , -1 , sizeof dpT);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> N >> k >> p;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
		A[i] %= p;
	}
	cout << dp(1 , 0 , A[0]);
	return 0;
}