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

char a[55][55];

int main()
{
	IO_OP;
	
	int n;
	int adj[4][2] = {
		{1, -1},
		{1, 0},
		{1, 1},
		{2, 0}
	};
	memset(a, '#', sizeof(a));
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	bool ok = 1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i][j] == '.') {
				for(int k=0;k<4;k++) {
					int ii = i + adj[k][0], jj = j + adj[k][1];
					if(a[ii][jj] == '.') {
						a[ii][jj] = '#';
					} else {
						ok = 0;
					}
				}
			}
			a[i][j] = '#';
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}