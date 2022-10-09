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

li n;

inline bool read() 
{
	cin >> n;
	return true;
}

int sum(li z)
{
	if(!z) return 0;
	return z % 10 + sum(z / 10);
}

inline void solve() 
{
	li x = 0;
	li cur = 1;
	while(x < n)
	{
		for(int i = 0; i < 9 && x < n; i++)
			x += cur;
		if(x >= n) break;
		cur *= 10;	
	}
	x -= cur;
//	cerr << x << endl;
	cout << sum(x) + sum(n - x) << endl;
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