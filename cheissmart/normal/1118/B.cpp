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

const int INF = 1e9 + 7, N = 2e5 + 7;

int p[N][2];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		p[i][0] = p[i-1][0], p[i][1] = p[i-1][1];
		p[i][i&1] += t;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(p[i-1][0] + p[n][1] - p[i][1] == p[i-1][1] + p[n][0] - p[i][0])
			cnt++;
	}
	cout << cnt << endl;

}