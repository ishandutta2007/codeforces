#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"

int No[100][100];
int DP[76][1 << 20];

const int kMod = 1e9 + 7;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int n;
	string s;

	cin >> n >> s;

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			No[i][j] = No[i][j - 1] * 2 + s[j - 1] - '0';
			No[i][j] = min(No[i][j], 22);
		}
	}

	int test = 0;
	for(int i = 1; i <= 20; ++i)
		test += __lg(i) + 1;
	cerr << test << endl;

	for(int i = 0; i < n; ++i, cerr << endl)
		for(int j = 0; j <= n; ++j)
			cerr << No[i][j] << " ";


	DP[0][0] = 1;

	int ans = 0;
	int maxx = 0;
	for(int e = 1; e <= n; ++e) {
		DP[e][0] = 1;
		for(int b = 0; b < e; ++b) {
			int no = No[b][e];
			if(no > 20 || no == 0) continue;
			--no;

			for(int old = 0; old <= maxx; ++old) {
				int nw = (old | (1 << no));
				DP[e][nw] += DP[b][old];
				if(DP[e][nw] >= kMod)
					DP[e][nw] -= kMod;
				maxx = max(maxx, nw);
			}
		}

		int old = ans;
		int msk = 0;
		for(int i = 0; i < 20; ++i) {
			msk |= (1 << i);
			ans += DP[e][msk];
			if(ans >= kMod)
				ans -= kMod;
		}
	

		// /cerr << "Step #" << e << ": " << ans - old << endl;
	}

	cout << ans << endl;

	return 0;
}