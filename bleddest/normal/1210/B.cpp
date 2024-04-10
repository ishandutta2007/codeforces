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

const int N = 7043;

li a[N];
li b[N];

int n;

bool read()
{
 	if(!(cin >> n))
		return false;
	forn(i, n) cin >> a[i];
	forn(i, n) cin >> b[i];	
	return true;
}

void solve()
{
	map<li, int> cnt;
	forn(i, n) cnt[a[i]]++;
	li ans = 0;
	vector<li> pos;
	for(auto x : cnt) if(x.y > 1) pos.pb(x.x);
	forn(i, n)
	{
		for(auto y : pos)
		{
			if((y & a[i]) == a[i])
			{
				ans += b[i];
				break;
			}
		}
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