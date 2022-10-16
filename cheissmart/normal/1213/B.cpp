#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[150005];

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		int mn = a[n-1];
		int ans = 0;
		for(int i=n-2;i>=0;i--) {
			if(a[i] > mn)
				ans++;
			mn = min(mn, a[i]);
		}
		cout << ans << endl;
	}	
	
}