//in the name of Flying Spaghetti Monster

#include<bits/stdc++.h>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = acosl(-1.0);

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define sz(a) (int)((a).size())

template<class A, class B> ostream& operator <<(ostream& out, pair<A, B> p)
{
	return out << "(" << p.x << ", " << p.y << ")";	
}

template<class A> ostream& operator <<(ostream& out, vector<A> v)
{
	out << "[";
	for(int i = 0; i < sz(v); i++)
	{
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(0));
mt19937_64 rnd64(time(0));

const li N = 300043;

int n;
li x1, x2;
pair<li, int> a[N];

bool read()
{
	if(scanf("%d %lld %lld", &n, &x1, &x2) != 3)
		return false;
	forn(i, n) scanf("%lld", &a[i].x);
	forn(i, n) a[i].y = i + 1;
	return true;	
}

bool construct(li s1, li s2, vector<int>& a1, vector<int>& a2)
{
	int good_pref = -1;
	for(int i = 0; i < n; i++)
	{
		if(a[i].x * (i + 1) >= s1)
		{
			good_pref = i + 1;
			break;
		}
	}	
	if(good_pref == -1)
		return false;
	for(int j = good_pref; j < n; j++)
	{
		if(a[j].x * (j + 1 - good_pref) >= s2)
		{
			forn(z, good_pref) a1.pb(a[z].y);
			fore(z, good_pref, j + 1) a2.pb(a[z].y);
			return true;
		}
	}
	return false;
}

void solve()
{
	sort(a, a + n);
	reverse(a, a + n);
	vector<int> a1, a2;
	if(construct(x1, x2, a1, a2))
	{
		puts("Yes");
		printf("%d %d\n", sz(a1), sz(a2));
		for(auto x : a1) printf("%d ", x);
		puts("");
		for(auto x : a2) printf("%d ", x);
		puts("");
	}
	else if (construct(x2, x1, a2, a1))
	{
		puts("Yes");
		printf("%d %d\n", sz(a1), sz(a2));
		for(auto x : a1) printf("%d ", x);
		puts("");
		for(auto x : a2) printf("%d ", x);
		puts("");
	}
	else puts("No");
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	ld curt = clock();
#endif
	if(read())
	{
		solve();
#ifdef _DEBUG
		cerr << "Execution time: " << (clock() - curt) / CLOCKS_PER_SEC << endl;
#endif
	}
	return 0;
	
}