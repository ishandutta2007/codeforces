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

char buf[N];
string s;
int n;
string ans;
vector<int> used;
vector<int> chars;

bool read()
{
	scanf("%d", &n);
	scanf("%s", buf);
	s = buf;
	return true;
}

bool try_solve(int x)
{
	used = vector<int>(n);
	int last1 = 0;
	int last2 = x;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(chars[i] < x)
		{
			if(last1 > chars[i]) cnt = 1;
			else
			{
				last1 = chars[i];
				used[i] = 1;
			}
		}
		if(chars[i] == x)
		{
			if(last2 == x) used[i] = 2;
			else
			{
				last1 = x;
				used[i] = 1;
			}
		}
		if(chars[i] > x)
		{
			if(last2 > chars[i]) cnt = 1;
			else 
			{
				last2 = chars[i];
				used[i] = 2;
			}
		}
	}
	if(cnt == 0)
		return true;
	return false;
}

void solve()
{
	chars = vector<int>(n);
	for(int i = 0; i < n; i++) chars[i] = s[i] - '0';
	for(int i = 0; i <= 9; i++)
		if(try_solve(i))
		{
			for(int i = 0; i < n; i++)
				printf("%d", used[i]);
			puts("");
			return;
		}
	puts("-");	
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	ld curt = clock();
#endif        
	cout << setprecision(15) << fixed;
	cerr << setprecision(15) << fixed;
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		read();
		solve();
#ifdef _DEBUG
		cerr << (clock() - curt) << endl;
#endif
	}
}