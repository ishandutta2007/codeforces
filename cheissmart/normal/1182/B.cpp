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

char a[505][505];

int main()
{
	IO_OP;
	
	int n, m;
	vector<pi> v;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			cin >> a[i][j];
			if(a[i][j] == '*') {
				v.EB(i, j);
			}
		}
	}
	if(v.size() == 0) {
		cout << "NO" << endl;
		return 0;
	}
	for(pi p:v) {
		int x = p.F, y = p.S;
		if(a[x+1][y] == '*' && a[x-1][y] == '*' && a[x][y+1] == '*' && a[x][y-1] == '*') {
			for(int i=x+1;a[i][y] == '*';i++)
				a[i][y] = '.';
			for(int i=x-1;a[i][y] == '*';i--)
				a[i][y] = '.';
			for(int i=y+1;a[x][i] == '*';i++)
				a[x][i] = '.';
			for(int i=y-1;a[x][i] == '*';i--)
				a[x][i] = '.';
			a[x][y] = '.';
			break;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j] == '*') {
				cout << "NO" << endl;
				return 0;
			}
	cout << "YES" << endl;
}