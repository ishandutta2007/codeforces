#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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

const int N = 1 << 9;
int h, w, q;
string s[N];
int sum[N][N];
int cnt_row[N][N];
int cnt_col[N][N];

int calc(int r1, int c1, int r2, int c2)
{
	return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

int get_row(int row, int l, int r)
{
	int res = cnt_row[row][r] - cnt_row[row][l];
	if (s[row][l] == '.')
		res++;
	return res;
}

int get_col(int col, int l, int r)
{
	int res = cnt_col[col][r] - cnt_col[col][l];
	if (s[l][col] == '.')
		res++;
	return res;
}

int hor(int r1, int c1, int r2, int c2)
{
	int ans = 0;
	FOR(i, r1, r2 + 1)
		ans += get_row(i, c1, c2);
	
	return ans;
}

int ver(int r1, int c1, int r2, int c2)
{
	int ans = 0;
	FOR(i, c1, c2 + 1)
		ans += get_col(i, r1, r2);
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> h >> w;
	s[0].assign(w + 1, '#');
	FOR(i, 1, h + 1)
	{
		cin >> s[i];
		s[i] = "#" + s[i];
	}
	
	FOR(i, 1, h + 1)
		FOR(j, 1, w + 1)
			sum[i][j] = (s[i][j] == '.') + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];

	FOR(i, 1, h + 1)
	{
		int now = 0;
		int j = 1;
		while(1)
		{
			while (j <= w && s[i][j] == '#')
				cnt_row[i][j++] = now;
			
			if (j > w)
				break;
			
			now++;
			while(j <= w && s[i][j] == '.')
				cnt_row[i][j++] = now;
		}
	}
	
	FOR(i, 1, w + 1)
	{
		int now = 0;
		int j = 1;
		while(1)
		{
			while (j <= h && s[j][i] == '#')
				cnt_col[i][j++] = now;
			
			if (j > h)
				break;
			
			now++;
			while(j <= h && s[j][i] == '.')
				cnt_col[i][j++] = now;
		}
	}
	
	cin >> q;
	while(q--)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = 2 * calc(r1, c1, r2, c2);
		
		ans -= hor(r1, c1, r2, c2);
		ans -= ver(r1, c1, r2, c2);
		cout << ans << endl;
	}
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}