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

const int INF = 1e9 + 7, MX = 50004;

signed main()
{
	IO_OP;
	
	int t;
	cin >>t ;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = INF;
		int x, y, z;
		for(int i = 1; i <= MX; i++) {
			for(int j = i; j <= MX; j+=i) {
				int cost = abs(i - a) + abs(j - b);
				int k;
				if(j <= c) {
					cost += min(c % j, j - c % j);
					if(c % j < j - c % j) {
						k = c - c % j;
					} else {
						k = c + j - c % j;
					}
				} else {
					cost += j - c;
					k = j;
				}
				if(cost < ans) {
					ans = cost;
					x = i, y = j, z = k;
				}
			}
		} 
		cout << ans << endl;
		cout << x << " " << y << " " << z << endl;
 	}	
	
}