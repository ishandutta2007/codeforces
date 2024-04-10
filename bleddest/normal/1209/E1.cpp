#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define all(a) (a).begin(), (a).end() 
#define sz(a) (int((a).size()))

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const int MOD = INF + 7;
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(-1.0);

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B>& p)
{
	return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream& out, const vector<A>& p)
{
	out << "[";
	forn(i, sz(p))
	{
	 	if(i) out << ", ";
		out << p[i];
	}
	return out << "]";

}

int n, m;

const int N = 13;
const int M = 2043;

int a[N][M];
int b[N][N];

int dp[13][1 << 12];
int aux[1 << 12];

vector<pt> z;


bool read()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	return true;
}

void solve()
{
	z.clear();
	for(int i = 0; i < m; i++)
	{
		int v = -1;
		for(int j = 0; j < n; j++)
			v = max(v, a[j][i]);
		z.pb(mp(v, i));
	}
	sort(all(z));
	reverse(all(z));
	m = min(m, n);
	for(int i = 0; i < m; i++)
	{
		int k = z[i].y;
		for(int j = 0; j < n; j++)
			b[j][i] = a[j][k];
	}
	memset(dp, 0, sizeof dp);
	int ms = (1 << n);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < ms; k++)
				aux[k] = dp[i][k];
			for(int k = 0; k < n; k++)
			{
				int num = b[(j + k) % n][i];
				for(int v = 0; v < ms; v++)
					if((v & (1 << k)) == 0)
						aux[v ^ (1 << k)] = max(aux[v ^ (1 << k)], aux[v] + num);
			}
			for(int k = 0; k < ms; k++)
				dp[i + 1][k] = max(dp[i + 1][k], aux[k]);
		}
	}
	printf("%d\n", dp[m][ms - 1]);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	ld curt = clock();
#endif        
	cout << setprecision(15) << fixed;
	cerr << setprecision(15) << fixed;
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		read();
		solve();
	#ifdef _DEBUG
		cerr << (clock() - curt) << endl;
	#endif
	}
}