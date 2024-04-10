#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int p[12][105][105];

int main()
{
	IO_OP;
	
	int n, q, c;
	cin >> n >> q >> c;
	for(int i=0;i<n;i++) {
		int x, y, s;
		cin >> x >> y >> s;
		p[s][x][y]++;
	}
	for(int i=0;i<=10;i++)
		for(int j=1;j<=100;j++)
			for(int k=1;k<=100;k++)
				p[i][j][k] += p[i][j-1][k] + p[i][j][k-1] - p[i][j-1][k-1];
	while(q--) {
		int ans = 0, t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		for(int s=0;s<=10;s++) {
			int d = (s + t) % (c + 1);
			ans += d * (p[s][x2][y2]-p[s][x2][y1-1]-p[s][x1-1][y2]+p[s][x1-1][y1-1]);
		}
		cout << ans << endl;
	}
	
}