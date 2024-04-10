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

template<class A, class B> ostream& operator << (ostream &out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, const vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));



int level(li x)
{
	if(x == 1)
		return 0;
	return level(x / 2) + 1;
}

li cnt_level(int x)
{
	if(x > 61)
		return INF64;
	return (1ll << x);
}

li norm(li x, li mod)
{
	x = (x % mod + mod) % mod;
	return x;
}

li lf_level(int x)
{
	return (1ll << x);
}

li rg_level(int x)
{
	return (2ll << x);
}

map<int, li> diff;

void proc_1(int x, li shift)
{
	li cur = diff[x - 1];
	cur = norm(cur + shift, cnt_level(x));
	diff[x - 1] = cur;
	cur = diff[x];
	cur = norm(cur - shift * 2, cnt_level(x + 1));
	diff[x] = cur;
}

void proc_2(int x, li shift)
{
	li cur = diff[x - 1];
	cur = norm(cur + shift, cnt_level(x));
	diff[x - 1] = cur;
}

void proc_3(li x, int lv)
{
	printf("%lld", x);
	if(x == 1)
		puts("");
	else
	{
		printf(" ");
		li offset = x - lf_level(lv);
		offset = norm(offset + diff[lv - 1], cnt_level(lv));
		proc_3((lf_level(lv) + offset) / 2, lv - 1); 
	}
}

int q;

bool read() {
 	if(scanf("%d", &q) != 1)
 		return false;
 	return true;
}

void solve() {
	forn(i, q)
	{
		int t;
		scanf("%d", &t);
		if(t < 3)
		{
			li x, k;
			scanf("%lld %lld", &x, &k);
			if(x != 1)
			{
				if(t == 1) proc_1(level(x), k);
				else proc_2(level(x), k);
			}
		}
		else
		{
			li x;
			scanf("%lld", &x);
			proc_3(x, level(x));
		}
	}
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	if(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}