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

int n, k;
const int N = 100043;
int cnt = 0;

int p[N];

void init()
{
	for(int i = 0; i < n; i++) p[i] = i;
}

int get(int x)
{
	return (p[x] == x ? x : (p[x] = get(p[x])));
}

bool merge(int x, int y)
{
	x = get(x);
	y = get(y);
	if(x == y) return false;
	p[x] = y;
	return true;
}


bool read()
{
	scanf("%d %d", &n, &k);
	init();
	for(int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		if(!merge(x, y))
			cnt++;
	}
	return true;
}

void solve()
{
	printf("%d\n", cnt);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	ld curt = clock();
#endif        
	cout << setprecision(15) << fixed;
	cerr << setprecision(15) << fixed;
	read();
	solve();
#ifdef _DEBUG
	cerr << (clock() - curt) << endl;
#endif
}