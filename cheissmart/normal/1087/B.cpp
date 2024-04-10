#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) {
		if(n % i == 0) {
			if(n / i < k) {
				cout << k*i + n/i << endl;
				return 0;
			}
		}
	}
}