/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()

const int MOD = 1e9 + 7;
inline void add( int &a, int b ) { if ((a += b) >= MOD) a -= MOD; }
inline void sub( int &a, int b ) { if ((a -= b) < 0) a += MOD; }

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int k, n;
	string s;
	cin >> n >> k >> s;
	int last = 1;
	vector<int> pos(k, -1), f(k, 0);
	forn(i, sz(s) + n) {
		int c = 0;
		if (i < sz(s))
			c = s[i] - 'a';
		else 
			forn(i, k)
				if (pos[i] < pos[c])
					c = i;
		//printf("i = %d, c = %d, last = %d, f = %d\n", i, c, last, f[c]);
		int tmp = f[c];
		f[c] = last, pos[c] = i;
		add(last, last);
		sub(last, tmp);
	}
	cout << last << endl;
}