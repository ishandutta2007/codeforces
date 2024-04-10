#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);
#define ull unsigned long long
 
using namespace std;
 
const int nax = 2e5 + 111; 
 
string s; 

map <pair<int, int>, int> mapa;
 
int main() {	
	boost;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cin >> s;
		mapa.clear();
		int X = 0;
		int Y = 0;
		mapa[{0, 0}] = 0;
		int dl = n + 1;
		int l = -1, r = 0;
		s = '#' + s;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == 'L') X--;
			if (s[i] == 'R') X++;
			if (s[i] == 'U') Y++;
			if (s[i] == 'D') Y--;
			if (mapa.find(mp(X, Y)) != mapa.end()) {
				int L = mapa[mp(X, Y)];
				int DL = i - L;
				if (DL < dl) {
					dl = DL;
					l = L;
					r = i;
				}
			}
			mapa[mp(X, Y)] = i;
		}
		if (l == -1) printf ("-1\n");
		else printf ("%d %d\n", l + 1, r);
		
	}
			
	
	
	return 0;
}