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

const int INF = 1e9 + 7;

int a[505][505], b[505][505];
int n, m;

void go1(int a[][505], vi& v, int row) {
	for(int i=row,j=0;i>=0&&j<m;i--,j++)
		v.PB(a[i][j]);
}

void go2(int a[][505], vi& v, int col) {
	for(int i=n-1,j=col;i>=0&&j<m;i--,j++)
		v.PB(a[i][j]);
}

signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> b[i][j];
	for(int i=0;i<n;i++) {
		vi x, y;
		go1(a, x, i), go1(b, y, i);
		sort(ALL(x)), sort(ALL(y));
		if(x != y) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i=0;i<m;i++) {
		vi x, y;
		go2(a, x, i), go2(b, y, i);
		sort(ALL(x)), sort(ALL(y));
		if(x != y) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}