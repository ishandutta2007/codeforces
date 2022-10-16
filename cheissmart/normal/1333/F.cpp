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

const int INF = 1e9 + 7, N = 5e5 + 7;

int pre[N], vis[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	int cnt = 0;
	for(int i=n-1;i>=1;i--) {
		for(int j=(i+1)*2;j<=n;j+=i+1) cnt -= vis[j], vis[j] = 0;
		vis[i+1] = 1;
		cnt++;
		pre[i] = cnt + i;
	}
	int j = 1;
	for(int i=2;i<=n;i++) {
		while(pre[j] < i) j++;
		cout << j << " ";
	}
	cout << endl;
	
}