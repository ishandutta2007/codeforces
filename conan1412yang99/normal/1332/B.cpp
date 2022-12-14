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


signed main()
{
	IO_OP;
	vi ps({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<int, vi> mp;
		for(int i=0;i<n;i++) {
			int t;
			cin >> t;
			for(int p:ps) {
				if(t % p == 0) {
					mp[p].PB(i);
					break;
				}
			}
		}
		cout << mp.size() << endl;
		vi ans(n);
		int cnt = 1;
		for(auto p:mp) {
			for(int e:p.S) ans[e] = cnt;
			cnt++;
		}
		for(int i=0;i<n;i++) cout << ans[i] << " ";
		cout << endl;
	}	
	
}