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

int n, k;

string s;
string st[70];

bool read() {
 	if(!(cin >> n >> k))
 		return false;
 	return true;
}

void solve() {
	vector<string> ans(n);
	int lst = 0;
	for(int i = 0; i < k - 1; i++)
	{
	 	ans[i] = st[lst++];
	}
	for(int i = k - 1; i < n; i++)
	{
	 	string t;
	 	cin >> t;
	 	if (t == "NO")
	 		ans[i] = ans[i - k + 1];
		else
			ans[i] = st[lst++];
	}
	for(auto z : ans) cout << z << " ";
}

int main() {
	                                                                                                                      
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	for(char c = 'A'; c <= 'Z'; c++)
	{
	 	s.push_back(c);
	}
	for(int i = 0; i < 26; i++)
	{
	 	st[i].push_back(s[i]);
	}
	for(int i = 0; i < 25; i++)
	{
	 	st[i + 26].push_back(s[i]);
	 	st[i + 26].push_back(s[i + 1] - 'A' + 'a');
	}


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