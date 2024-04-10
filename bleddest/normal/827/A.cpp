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

int n;
const int M = 100 * 1000 + 43;
const int N = 1000 * 1000 + 43;
char buf[N];
string s[M];
char ans[2 * N];
int nxt[2 * N];

int get_next(int i)
{
	return (ans[nxt[i]] == '-' ? nxt[i] : nxt[i] = get_next(nxt[i])); 	
}

bool read() {
 	if(scanf("%d", &n) != 1)
 		return false;
 	forn(i, 2 * N)
 	{
 		nxt[i] = i + 1;
 		ans[i] = '-';
 	}
 	forn(i, n)
 	{
 	 	scanf("%s", buf);
 	 	s[i] = buf;
 	 	int k;
 	 	scanf("%d", &k);
 	 	forn(j, k) 
 	 	{
 	 	 	int x;
 	 	 	scanf("%d", &x);
 	 	 	--x;
 	 	 	int e = x + sz(s[i]);
 	 	 	int z = x;
 	 	 	while(z < e)
 	 	 	{
 	 	 	 	ans[z] = s[i][z - x];
 	 	 	 	z = get_next(z);
 	 	 	}
 	 	}
 	}
 	int mx = 0;
 	forn(i, 2 * N) 
 		if (ans[i] != '-')
 			mx = i;
 		else
 			ans[i] = 'a';
 	forn(i, mx + 1)
 		printf("%c", ans[i]);
 	return true;
}

void solve() {
	
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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