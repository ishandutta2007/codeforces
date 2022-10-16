#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;
int n;

int h2i(char c) {
	if(isdigit(c)) return c - '0';
	return c - 'A' + 10;
}

int p[5252][5252];

bool ok(int x) {
	int m = n / x;
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			int r = i * x, c = j * x;
			int rr = (i + 1) * x, cc = (j + 1) * x;
			int s = p[rr][cc] - p[r][cc] - p[rr][c] + p[r][c];
			if(s != 0 && s != x * x)
				return false;
		}
	}
	return true;
}

int main()
{
	IO_OP;
	cin >> n;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<n/4;j++) {
			char h;
			cin >> h;
			int t = h2i(h);
			for(int k=4;k>=1;k--) {
				p[i][j*4+k] = t % 2;
				t /= 2;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			p[i][j] += p[i][j-1] + p[i-1][j] - p[i-1][j-1];

	int mx = 1;
	for(int i=1;i<=n;i++) {
		if(n % i) continue;
		if(ok(i)) mx = max(mx, i);
	}
	cout << mx << endl;
}