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

const int N = 200043;

map<int, int> cnt;
int fullcnt[N];
int a[N];
int mx = 0;
int good = 0;
int ans;
int n, q;

int getcnt(int x)
{
	if(cnt.count(x)) return cnt[x];
	return 0;
}

int is_good(int x)
{
	int v = getcnt(x);
	if(v == fullcnt[x] || v == 0)
		return 1;
	return 0;
}

void add(int x)
{
	good -= is_good(x);
	cnt[x]++;
	mx = max(mx, cnt[x]);
	good += is_good(x);
}

void update_answer()
{
	if(good == 0)
	{
		cnt.clear();
		ans -= mx;
		mx = 0;
	}
}

bool read()
{
	scanf("%d %d", &n, &q);
	ans = n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		fullcnt[a[i]]++;
	}
	return true;
}

void solve()
{
	for(int i = 0; i < n; i++)
	{
		add(a[i]);
		update_answer();
	}
	printf("%d\n", ans);
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