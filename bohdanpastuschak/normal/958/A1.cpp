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
int n;
string s[10];
char newS[10][10];
char newS2[10][10];
string t[10];

void rotate()
{
	int ptr = 0;
	for(int j = 0; j < n; j++)
		for(int i = n - 1; i >= 0; i--)
		{
			newS[ptr / n][ptr % n] = t[i][j];
			ptr++;
		}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			t[i][j] = newS[i][j];
		}
	}
}
void checkIdentity()
{
	bool isGood = true;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			isGood &= s[i][j] == t[i][j];
		}
	}
	if(isGood)
	{
		cout << "Yes";
		exit(0);
	}
}
void flip1()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			newS[n - 1 - i][j] = t[i][j];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			t[i][j] = newS[i][j];
		}
	}
}
void flip2()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			newS[i][n - 1 - j] = t[i][j];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			t[i][j] = newS[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];

	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < 4; i++)
	{
		checkIdentity();
		rotate();
		
	}
	flip1();
	for(int i = 0; i < 4; i++)
	{
		checkIdentity();
		rotate();
	}
	flip1();
	flip2();
	for(int i = 0; i < 4; i++)
	{
		checkIdentity();
		rotate();
	}
	cout << "No";
	return 0;
}