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

const int N = 100043;

int a[N];
int b[N];
int n;

inline bool read() 
{
	scanf("%d", &n);
	forn(i, n) scanf("%d %d", &a[i], &b[i]);
	return true;
}

inline void solve() 
{
	li ans = 0;
	sort(a, a + n);
	sort(b, b + n);
	forn(i, n) ans += 1 + max(a[i], b[i]);
	printf("%lld\n", ans);
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