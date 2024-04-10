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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int ans[1024], a[1024];

signed main()
{
	IO_OP;
	
	int n, m, d, sm = 0;
	cin >> n >> m >> d;
	for(int i=1;i<=m;i++) {
		cin >> a[i];
		sm += a[i];
	}
	int j=0;
	for(int i=1;i<=m;i++) {
		int put = min(j+d, n-sm+1);
		sm -= a[i];
		for(j=put;j<put+a[i];j++)
			ans[j] = i;
		j--;
	}
	if(n+1-j > d) {
		cout << "NO"<< endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
		
}