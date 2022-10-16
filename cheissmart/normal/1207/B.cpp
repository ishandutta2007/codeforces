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

int a[55][55], b[55][55];
vector<pi> v;

void f(int i, int j) {
	v.EB(i, j);
	b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
}

bool ok(int i, int j) {
	return a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1;
}

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(ok(i, j))
				f(i, j);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j] != a[i][j]) {
				cout << -1 << endl;
				return 0;
			}
	cout << v.size() << endl;
	for(pi p:v)
		cout <<p.F << " " << p.S << endl;
}