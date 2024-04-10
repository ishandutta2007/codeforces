#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(2e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, x, y, d;
		cin >> n >> x >> y >> d;
		if((y-x)%d == 0) {
			cout << abs(y - x) / d << endl;
		} else {
			int ans1 = INF, ans2 = INF;
			if((y - 1) % d == 0 || (n - y) % d == 0) {
				if((y - 1) % d == 0) {
					ans1 = (x-1+d-1)/d + (y - 1)/d;
				} 
				if((n - y) % d == 0){
					ans2 = (n-x+d-1)/d + (n - y) / d;
				}
				cout << min(ans1, ans2) << endl;
			} else {
				cout << -1 << endl;
			}
			
		}
	}
}