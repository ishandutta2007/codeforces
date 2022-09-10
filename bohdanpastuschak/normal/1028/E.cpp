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

int n;
LL a[1 << 20];
LL b[1 << 20];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> b[i];

	bool all0 = 1;
	FOR(i, 0, n)
		all0 &= b[i] == b[0];
	
	if (all0)
	{
		if (b[0] == 0)
		{
			cout << "YES" << endl;
		FOR(i, 0, n)
			cout << 1 << " ";
		cout << endl;
		}
		else
			cout << "NO" << endl;
		return 0;
	}
	
	int shift = 0;
	FOR(i, n, n << 1)
		b[i] = b[i - n];
	
	
	while(b[shift] <= b[n + shift - 1])
		shift++;
	
	//cout << shift << endl;
	
	a[0] = b[shift];
	a[n] = a[0];
	RFOR(i, n, 1)
	{
		LL I = 1;
		if (b[i - 1 + shift] >= b[i + shift])
			I += (b[i - 1 + shift] - b[i + shift]) / a[i + 1];
		
		a[i] = b[i + shift] + I * a[i + 1];
	}
	
	
	FOR(i, n, n << 1)
		a[i] = a[i - n];
	
	cout << "YES" << endl;
	FOR(i, n - shift, n - shift + n)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}