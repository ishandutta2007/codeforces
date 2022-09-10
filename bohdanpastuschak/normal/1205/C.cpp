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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
bool ask(int x1, int y1, int x2, int y2)
{
	assert(x1 <= x2);
	assert(y1 <= y2);
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	fflush(stdout);
	bool ret;
	cin >> ret;
	return ret;
}
 
const int N = 57;
int n;
char a[N][N];
 
bool go(int x, int y, bool first)
{
	if (first)
	{
		bool r1 = ask(x, y - 2, x + 1, y);
		bool r2 = ask(x, y - 1, x + 2, y);
		
		if (a[x][y - 1] == a[x + 1][y])
		{
			char maje;
			if (r1 || r2)
				maje = a[x + 2][y];
			else
				maje = !a[x + 2][y];
			
			return a[x][y - 1] != maje;
		}
		else
		{
			char maje;
			if (r1 || r2)
				maje = a[x][y];
			else
				maje = !a[x][y];
			
			return a[x][y - 1] != maje;
		}
	}
	else
	{
		bool r1 = ask(x - 2, y, x, y + 1);
		bool r2 = ask(x - 1, y, x, y + 2);
		
		if (a[x - 1][y] == a[x][y + 1])
		{
			char maje;
			if (r1 || r2)
				maje = a[x][y + 2];
			else
				maje = !a[x][y + 2];
			
			return a[x - 1][y] != maje;
		}
		else
		{
			char maje;
			if (r1 || r2)
				maje = a[x][y];
			else
				maje = !a[x][y];
			
			return a[x - 1][y] != maje;
		}
	}
}
 
bool treba()
{
	FOR(i, 1, n + 1)
		FOR(j, 1, n + 1)
		{
			if (j + 3 <= n)
			{
				if ((a[i][j] ^ a[i][j + 2]) ==
					(a[i][j + 1] ^ a[i][j + 3]))
					{
						bool ye = ask(i, j, i, j + 3);
						char maje = a[i][j] ^ !ye;
						return a[i][j + 3] != maje;
					}
			}
			
			if (i + 3 <= n)
			{
				if ((a[i][j] ^ a[i + 2][j]) ==
					(a[i + 1][j] ^ a[i + 3][j]))
					{
						bool ye = ask(i, j, i + 3, j);
						char maje = a[i][j] ^ !ye;
						return a[i + 3][j] != maje;
					}
			}
			
			if (i + 2 <= n && j + 1 <= n)
			{
				if ((a[i][j] ^ a[i + 1][j + 1])== 
					(a[i][j + 1] ^ a[i + 2][j + 1]))
					{
						bool ye = ask(i, j, i + 2, j + 1);
						char maje = a[i][j] ^ !ye;
						return a[i + 2][j + 1] != maje;
					}
			}
			
			if (i + 1 <= n && j + 2 <= n)
			{
				if ((a[i][j] ^ a[i + 1][j + 1]) == 
					(a[i][j + 1] ^ a[i + 1][j + 2]))
					{
						bool ye = ask(i, j, i + 1, j + 2);
						char maje = a[i][j] ^ !ye;
						return a[i + 1][j + 2] != maje;
					}
			}
			
		} 
	
	assert(0);
}
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FILL(a, -1);
	a[1][1] = 1;
	a[1][2] = 1;
	a[n][n] = 0;
	
	FOR(i, 1, n + 1)
		FOR(j, 1, n + 1)
		{
			if (a[i][j] != -1 || ((i + j) % 2 == 1))
				continue;
			
			if (j > 2)
				a[i][j] = a[i][j - 2] ^ !ask(i, j - 2, i, j);
			else
				if (i > 2)
					a[i][j] = a[i - 2][j] ^ !ask(i - 2, j, i, j);
				else
					a[i][j] = a[i - 1][j - 1] ^ !ask(i - 1, j - 1, i, j);
		}
	
	FOR(i, 1, n + 1)
		FOR(j, 1, n + 1)
		{
			if (a[i][j] != -1 || ((i + j) % 2 == 0))
				continue;
			
			if (j > 2 && a[i][j - 2] != -1)
				a[i][j] = a[i][j - 2] ^ !ask(i, j - 2, i, j);
			else
				if (i > 2 && a[i - 2][j] != -1)
					a[i][j] = a[i - 2][j] ^ !ask(i - 2, j, i, j);
				else
					if (a[i - 1][j - 1] != -1)
						a[i][j] = a[i - 1][j - 1] ^ !ask(i - 1, j - 1, i, j);
		}
	
	a[2][1] = a[3][2] ^ !ask(2, 1, 3, 2);
	
	FOR(i, 1, n + 1)
		FOR(j, 1, n + 1)
		{
			if (a[i][j] != -1 || ((i + j) % 2 == 0))
				continue;
			
			if (j > 2 && a[i][j - 2] != -1)
				a[i][j] = a[i][j - 2] ^ !ask(i, j - 2, i, j);
			else
				if (i > 2 && a[i - 2][j] != -1)
					a[i][j] = a[i - 2][j] ^ !ask(i - 2, j, i, j);
				else
					if (a[i - 1][j - 1] != -1)
						a[i][j] = a[i - 1][j - 1] ^ !ask(i - 1, j - 1, i, j);
		}
		
	if (treba())
		FOR(i, 1, n + 1)
			FOR(j, 1, n + 1)
				if ((i + j) & 1)
					a[i][j] ^= 1;
	
	cout << "!" << endl;
	fflush(stdout);
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, n + 1)
			cout << (int)a[i][j];
		cout << endl;
	}
	
	fflush(stdout);
 
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}