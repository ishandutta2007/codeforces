#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 14;

bool was[1<<N][N];
ll dp[1<<N][N];

pair<short, short> glob[100000000];
int szg = 0;


char matrix[N][N];

int tut[67];

int n;

void recursion(string &s, int start) {

	if (s.size() == n - 1) {
		ll kek = 0;
		
		for (int j = 0; j < n; ++j) {
			kek += dp[(1<<n)-1][j];
			dp[(1<<n)-1][j] = 0;
			was[(1<<n)-1][j] = false;
		}
	    cout << kek << "\n";
	    return;
	}

	for (int E = 0; E < 2; ++E) {
		
		s += (char) ('0' + E);

		int Was = szg;

		for (int j = start; j < Was; ++j) {
			int a = glob[j].first, b = glob[j].second;
			ll W = dp[a][b];
			//cout << s << " ==== " << a << " " << b << " " << start << " " << Was << " " << szg << " " << W << endl;

			//cout << E << " " << a << " " << b << " " << W << endl;

			int c = ((1<<n)-1)^a;
			while (c > 0) {
				int D = c&(-c);
				c ^= D;
				int pos = tut[D%67];
				if (matrix[b][pos] == s.back()) {
					int mask = a^(1<<pos), last = pos;
					if (!was[mask][last]) {
						was[mask][last] = true;
						glob[szg++] = {mask, last};
					}
					dp[mask][last] += W;
				}
			}
			if (E==1) dp[a][b] = 0;
			if (E==1) was[a][b] = false;
		}

		recursion(s, Was);
		s.pop_back();
		szg=Was;

	}

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 30; ++i) {
		tut[(1<<i)%67] = i;
	}

	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> matrix[i][j];
	}
	int tot = 0;

	for (int i = 0; i < n; ++i) {
		was[1<<i][i] = true;
		dp[1<<i][i] = 1;
		glob[szg++] = {(1<<i), i};
	}

	string Q = "";

	recursion(Q, 0);

}