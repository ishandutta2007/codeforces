#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
#define M 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int b[128][256];

string a[128]; 

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++) {
			b[i][a[j][i]] = 1;
		}
	ll ans = 1;
	for(int i=0;i<m;i++) {
		int ct = 0;
		for(int j=0;j<256;j++)
			ct += b[i][j];
		ans *= ct;
		ans %= M;
	}
	cout << ans << endl;
}