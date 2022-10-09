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

const int N = 100043;

int days[N];
li add[N];
li ans[N];
li cnt_add[N];
int t[N];
int n;
int v[N];
li pref_t[N];

void add_range(int x, int y, li val)
{
	add[x] += val;
	add[y] -= val;
}

void affect(int x, int y)
{
	cnt_add[x]++;
	cnt_add[y]--;
}

void print()
{
	li cur = 0;
	int cur_cnt = 0;
	forn(i, n)
	{
		cur_cnt += cnt_add[i];
		cur += add[i];
		printf("%lld ", cur + cur_cnt * 1ll * t[i]);
	}
	puts("");
}

bool read() {
 	if(scanf("%d", &n) != 1)
 		return false;
 	forn(i, n) scanf("%d", &v[i]);
 	forn(i, n) scanf("%d", &t[i]);
 	return true;
}

void solve() {
	forn(i, n) pref_t[i + 1] = pref_t[i] + t[i];
	forn(i, n)
	{
		if(t[i] >= v[i])
		{
			add_range(i, i + 1, v[i]);
			continue;
		}
		int l = i;
		int lf = i;
		int rg = n + 1;
		while(rg - lf > 1)
		{
			int mid = (lf + rg) / 2;
			if(pref_t[mid] - pref_t[i] <= v[i])
				lf = mid;
			else
				rg = mid;
		}
		affect(l, lf);
		int rem = (v[i] - (pref_t[lf] - pref_t[l]));
	//	cerr << i << " " << lf << " " << rem << endl;
		add_range(lf, lf + 1, rem); 
	}
	print();
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