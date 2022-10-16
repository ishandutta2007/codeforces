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

int a[505][505], ans[505], vis[1023];

int main()
{
	IO_OP;
	
	int n, m, x = 0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		ans[i] = 1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
		x ^= a[i][1];
	}
	if(x > 0) {
		cout << "TAK" << endl;
		for(int i=1;i<=n;i++)
			cout << ans[i] << " ";
		return 0;
	}
	bool ok = 0;
	for(int i=1;i<=n;i++) {
		int k = 0;
		for(int j=1;j<=m;j++)
			if(a[i][j] != a[i][1])
				k = j;
		if(k) {
			ans[i] = k;	
			ok = 1;
			break;
		}
	}
	if(ok) {
		cout << "TAK" << endl;
		for(int i=1;i<=n;i++)
			cout << ans[i] << " ";
	} else {
		cout << "NIE" << endl;
	}
}