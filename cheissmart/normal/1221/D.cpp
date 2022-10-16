#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e18 + 7;

int a[300005], b[300005], dp[300005][3];

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++) 
			cin >> a[i] >> b[i];
		for(int i=0;i<3;i++)
			dp[0][i] = b[0] * i;
		for(int i=1;i<n;i++) {
			for(int j=0;j<3;j++) {
				dp[i][j] = INF;
				for(int k=0;k<3;k++)
					if(a[i-1]+k != a[i]+j)
						dp[i][j] =  min(dp[i][j], dp[i-1][k] + b[i]*j);
			}
		}
		cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
	}	
	
}