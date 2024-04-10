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

const int N = 143;
int n;
int a[N], b[N], f[N];

bool read()
{
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) if(s[i] == '1')
		f[i] = 1;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	return true;
}

int active(int i, int t)
{
	int cnt = 0;
	if(t >= b[i]) cnt = 1 + (t - b[i]) / a[i];
	return f[i] ^ (cnt % 2);
}

void solve()
{
	int ans = 0;
	for(int i = 0; i < 1337; i++)
	{
		int cur = 0;
		for(int j = 0; j < n; j++)
			cur += active(j, i);
		ans = max(ans, cur);
	}
	cout << ans << endl;
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