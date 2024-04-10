#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		bool flag = true;
		if(x == 0) {
			cout << 87 << " " << 1 << endl;
			continue;
		}
		for(int i=1;i*i<=x;i++) {
			if(x % i == 0 && (x/i + i) % 2 == 0) {
				int n = (x/i + i) / 2, k = n - i;
				if(k == 0) continue;
				int m = n / k;
				if(n/m == k) {
					cout << n << " " << m << endl;
					flag = false;
					break;
				}
			}
		}
		if(flag) cout << -1 << endl;
	}
	
}