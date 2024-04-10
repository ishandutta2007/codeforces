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

const int INF = 1e9 + 7, N = 2e5 + 7;

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, k;
		cin >> n >> k;
		vi v;
		ll sum = 0, tt = 0;
		for(int i=1;i<=n;i++) {
			int t;
			cin >> t;
			sum += t;
			if(sum & 1) {
				v.PB(i);
				sum = 0;
			}
			tt += t;
		}
		if(((tt & 1) ^ (k & 1)) || v.size() < k) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for(int i=0;i<k-1;i++) cout << v[i] << " ";
			cout << n << endl;
		}
	}	
	
}