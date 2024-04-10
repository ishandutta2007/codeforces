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

int a[505][505], b[505][505], r[505], c[505];

int main()
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
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			r[i] += a[i][j];
			r[i] += b[i][j];
			c[j] += a[i][j];
			c[j] += b[i][j];
		}
	}
	for(int i=0;i<n;i++)
		if(r[i] & 1) {
			cout << "No" << endl;
			return 0;
		}
	for(int i=0;i<m;i++)
		if(c[i] & 1) {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
}