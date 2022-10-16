#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int r[512][512], c[512][512];
char a[512][512];

int main()
{
	IO_OP;
	
	int h, w;
	cin >> h >> w;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin >> a[i][j];
	for(int i=1;i<=h;i++) {
		for(int j=2;j<=w;j++) {
			if(a[i][j] == '.' && a[i][j-1] == '.')
				r[i][j] = r[i][j-1]+1;
			else
				r[i][j] = r[i][j-1];
		}
	}
	for(int j=1;j<=w;j++) {
		for(int i=2;i<=h;i++) {
			if(a[i-1][j] == '.' && a[i][j] == '.')
				c[i][j] = c[i-1][j]+1;
			else
				c[i][j] = c[i-1][j];
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = 0;
		for(int rw=r1;rw<=r2;rw++)
			ans += r[rw][c2] - r[rw][c1];
		for(int co=c1;co<=c2;co++)
			ans += c[r2][co] - c[r1][co];
		cout << ans << endl;
	}
}