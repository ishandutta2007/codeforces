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

const int MAX = 3e5 + 47;
int n;
LL a[MAX];
LL b[MAX];
LL sa[MAX];
LL sb[MAX];
LL sra[MAX];
LL srb[MAX];
LL ca[MAX];
LL cb[MAX];
LL cra[MAX];
LL crb[MAX];

LL DP[MAX][2];

inline LL get(int pos, bool verh)
{
	if (pos == n)
		return 0;
		
	if (DP[pos][verh] != -1)
		return DP[pos][verh];
	
	LL res = 0;
	
	if (verh)
		res = max(ca[pos] + crb[pos] + sb[pos] * (n - pos), b[pos] + get(pos + 1, verh ^ 1) + 2 * (sa[pos + 1] + sb[pos + 1]));
	else
		res = max(cra[pos] + cb[pos] + sa[pos] * (n - pos), get(pos + 1, verh ^ 1) + sa[pos + 1] + sb[pos + 1] * 2 + sa[pos]);
			
	return DP[pos][verh] = res;
}


int main()
{ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)	
		cin >> a[i];
	FOR(i, 0, n)
		cin >> b[i];
	
	sa[n - 1] = a[n - 1];
	RFOR(i, n - 1, 0)
		sa[i] = sa[i + 1] + a[i];
	
	sb[n - 1] = b[n - 1];
	RFOR(i, n - 1, 0)
		sb[i] = sb[i + 1] + b[i];
	
	sra[0] = a[0];
	FOR(i, 1, n)
		sra[i] = sra[i - 1] + a[i];
	
	srb[0] = b[0];
	FOR(i, 1, n)
		srb[i] = srb[i - 1] + b[i];	
		
	ca[n - 1] = 0;
	RFOR(i, n - 1, 0)
		ca[i] = ca[i + 1] + sa[i + 1];
	
	cb[n - 1] = 0;
	RFOR(i, n - 1, 0)
		cb[i] = cb[i + 1] + sb[i + 1];
	
	cra[n - 1] = 0;
	RFOR(i, n - 1, 0)
		cra[i] = cra[i + 1] + a[i] * (n - i - 1);
		
	crb[n - 1] = 0;
	RFOR(i, n - 1, 0)
		crb[i] = crb[i + 1] + b[i] * (n - i - 1);

	FILL(DP, -1);
	cout << get(0, 1) << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}