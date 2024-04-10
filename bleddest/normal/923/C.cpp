#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator << (ostream &out, pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]\n";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int N = 20000043;

int t[N];
int nxt[N][2];

int szt = 1;

int new_vertex()
{
	nxt[szt][0] = nxt[szt][1] = -1;
	t[szt] = 0;
	return szt++;
}

int go(int x, int y)
{
	if (nxt[x][y] == -1)
		nxt[x][y] = new_vertex();
	return nxt[x][y];
}

void add_number(int x, int val)
{
	int cur = 0;
	t[cur] += val;
	for(int i = 29; i >= 0; i--)
	{
		int z = ((x >> i) & 1);
		cur = go(cur, z);
		t[cur] += val;
	}
}

int descend(int x)
{
	int ans = 0;
	int cur = 0;
	for(int i = 29; i >= 0; i--)
	{
		int z = ((x >> i) & 1);
		int k;
		if(nxt[cur][z] != -1 && t[nxt[cur][z]] > 0)
			k = z;
		else
			k = z ^ 1;
		ans ^= (k << i);
		cur = go(cur, k);
	}
	return ans;
}

int n;

const int M = 300043;

int a[M];
int p[M];

bool read() {
 	if(scanf("%d", &n) != 1)
 		return false;
 	forn(i, n) scanf("%d", &a[i]);
 	forn(i, n) scanf("%d", &p[i]);
 	return true;
}

void solve() {
	nxt[0][0] = nxt[0][1] = -1;
	forn(i, n) add_number(p[i], 1);
	forn(i, n)
	{
		int z = descend(a[i]);
		printf("%d ", a[i] ^ z);
		add_number(z, -1);				
	}
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	while(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}