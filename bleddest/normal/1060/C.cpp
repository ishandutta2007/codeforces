#include<bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

mt19937 rnd(time(NULL));

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) 
{
	return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream &out, const vector<A> &v) 
{
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const int MOD = INF + 7;

const int N = 2043;
int a[N];
int b[N];
int maxlen[N * N];
int n, m;
li x;

inline bool read() 
{
	cin >> n >> m;
	forn(i, n) cin >> a[i];
	forn(i, m) cin >> b[i];
	cin >> x;
	return true;
}

inline void solve() 
{
	for(int i = 0; i < n; i++)
	{
		int cur = 0;
		for(int j = i; j < n; j++)
		{
			cur += a[j];
			maxlen[cur] = max(maxlen[cur], j - i + 1);
		}
	}
	for(int i = 0; i < N * N - 1; i++)
		maxlen[i + 1] = max(maxlen[i + 1], maxlen[i]);
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		int cur = 0;
		for(int j = i; j < m; j++)
		{
			cur += b[j];
			int mx = min(li(N * N - 1), x / cur);
			ans = max(ans, (j - i + 1) * maxlen[mx]); 
		}
	}
/*	forn(i, 10) cerr << maxlen[i] << " ";
	cerr << endl;*/
	cout << ans << endl;
}

int main() 
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	cout << fixed << setprecision(12);
	int tc;
	tc = 1;
	while(tc--)
	{
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}