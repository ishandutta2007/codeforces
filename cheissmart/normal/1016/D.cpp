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

int a[102], b[102], ans[102][102];

int main()
{
	IO_OP;
	
	int n, m, c = 0;
	cin >> n >> m;
	for(int i=0;i<n;c ^= a[i++])
		cin >> a[i];
	for(int i=0;i<m;c ^= b[i++])
		cin >> b[i];
	if(c) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	ans[0][0] = a[0];
	for(int i=1;i<m;i++)
		ans[0][0] ^= b[i];
	for(int i=1;i<m;i++)
		ans[0][i] = b[i];
	for(int i=1;i<n;i++)
		ans[i][0] = a[i];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}