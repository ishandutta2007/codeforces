//#include "grader.h"
#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
//#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
//const int ma = 128 * 1024, mal = 8;
const ll mod = ll(1e9) + 7;
int n, m, ans[10000], mink[10000], lst;

string s;

int main() {
	//iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	forn (i, n) {
		s = "";
		char c = getchar();
		while (c != '0' && c != '1') {
			c = getchar();
		}
		while (c == '0' || c == '1') {
			s += c;
			c = getchar();
		}
		//cout << s << endl;
		//cin >> s;
		int fi = -1, la = -1;
		forn (i, m) {
			if (s[i] == '1') {
				la = i;
				if (fi == -1)
					fi = i;
			} 
		}
		if (fi  == -1) {
			cout << -1;
			re 0;
		}
		lst = -(m - la);

		forn (i, m) {
			if (s[i] == '1')
				lst = i;
			mink[i] = i - lst;
		}
		lst = m + fi;
		for (int i = m - 1; i >= 0; i--) {
			if (s[i] == '1')
				lst = i;
			mink[i] = min(lst - i, mink[i]);
		}
		forn (i, m) {
			ans[i] += mink[i];
			if (mink[i] == int(1e9)) {
				cout << -1;
				re 0;
			}
		}
	}
	int mans = ans[0];
	forn (i, m)
		mans = min(mans, ans[i]);
	cout << mans;
}