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

int a[55][55], b[55][55];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> b[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			int x = a[i][j], y = b[i][j];
			a[i][j] = min(x, y);
			b[i][j] = max(x, y);
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m-1;j++)
			if(a[i][j] >= a[i][j+1]) {
				cout << "Impossible" << endl;
				return 0;
			}
	for(int j=0;j<m;j++) 
		for(int i=0;i<n-1;i++)
			if(a[i][j] >= a[i+1][j]) {
				cout << "Impossible" << endl;
				return 0;
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m-1;j++)
			if(b[i][j] >= b[i][j+1]) {
				cout << "Impossible" << endl;
				return 0;
			}
	for(int j=0;j<m;j++) 
		for(int i=0;i<n-1;i++)
			if(b[i][j] >= b[i+1][j]) {
				cout << "Impossible" << endl;
				return 0;
			}
	cout << "Possible" << endl;
	
}