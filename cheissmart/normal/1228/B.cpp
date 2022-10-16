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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int M = 1e9 + 7;

int a[1024][1024], b[1024][1024];

int32_t main()
{
	IO_OP;
	
	int h, w;
	cin >> h >>w;
	for(int i=0;i<h;i++) {
		int r;
		cin >> r;
		for(int j=0;j<r;j++)
			a[i][j] = 1;
		a[i][r] = 2;
	}
	for(int i=0;i<w;i++) {
		int c;
		cin >>c;
		for(int j=0;j<c;j++)
			b[j][i] = 1;
		b[c][i] = 2;
	}
	int ans = 1;
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			if(a[i][j] == 0 && b[i][j] == 0) {
				ans = ans * 2;
				ans %= M;
				continue;
			}
			if(a[i][j]+b[i][j] == 3) ans = 0;
		}
	}
	cout << ans << endl;
}