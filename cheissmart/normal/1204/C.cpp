#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int d[105][105], dp[1000006], lst[1000006], p[1000006];

int main()
{
	IO_OP;

	memset(dp, 0x3f, sizeof dp);
	memset(d, 0x3f, sizeof d);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			char c;
			cin >> c;
			if(c == '1')
				d[i][j] = 1;
		}
		d[i][i] = 0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
		cin >> p[i];
	dp[0] = 1;
	lst[0] = -1;
	for(int i=1;i<m;i++) {
		int u = p[i];
		for(int v=1;v<=n;v++) {
			int s = d[v][u];
			int j = i - s;
			if(j < 0) continue;
			if(p[j] == v) {
				if(dp[j]+1 < dp[i]) {
					dp[i] = dp[j] +1;
					lst[i] = j;
				}
			}
		}
	}
	cout << dp[m-1] << endl;
	vi v;
	int c = m-1;
	while(c != -1) {
		v.PB(c);
		c = lst[c];
	}
	reverse(ALL(v));
	for(int e:v)
		cout << p[e] << " ";
}