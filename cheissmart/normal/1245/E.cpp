#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 11;

double dp[N][N], dp2[N][N];
int a[N][N];

pi nxt(int i, int j) {
	if(i&1) {
		if(j+1 < 10) return {i, j+1};
		else return {i-1, j};
	} else {
		if(j-1 >= 0) return {i, j-1};
		else return {i-1, j};
	}
}

void upd(int i, int j) {
	pi p = {i, j};
	for(int k = 0; k < 6; k++) {
		p = nxt(p.F, p.S);
		dp[i][j] += (dp[p.F][p.S] + 1) / 6;
		dp2[i][j] += (dp[p.F][p.S] + 1) / 6;
	}
	if(a[i][j]) dp[i][j] = min(dp[i][j], dp2[i-a[i][j]][j]);
}

signed main()
{
	IO_OP;
	
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++) {
			cin >> a[i][j];
		}
	for(int i = 1; i < 6; i++) {
		double sum = 0;
		for(int j = 0; j < i; j++) sum += (dp[0][j] + 1) / 6;
		dp[0][i] = (sum + (6.-i)/6) * 6 / i;
		dp2[0][i] = dp[0][i];
	}
	for(int i = 6; i < 10; i++) upd(0, i);
	for(int i = 1; i < 10; i++) {
		if(i&1) {
			for(int j = 9; j >= 0; j--) upd(i, j);
		} else {
			for(int j = 0; j < 10; j++) upd(i, j);
		}
	}
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cerr << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << fixed << setprecision(10) << dp[9][0] << endl;

}