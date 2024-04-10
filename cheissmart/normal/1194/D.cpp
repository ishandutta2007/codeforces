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

int dp[200005];

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		if(k % 3) {
			if(n % 3) cout << "Alice" << endl;
			else cout << "Bob" << endl;
		} else {
			if(n < k) {	
				if(n % 3) cout << "Alice" << endl;
				else cout << "Bob" << endl;
			} else {
				n %= (k + 1);
				if(n == k) cout << "Alice" << endl;
				else {
					if(n % 3) cout << "Alice" << endl;
					else cout << "Bob" << endl;
				}
			}
		}
	}
	
}