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

bool isp(int n) {
	for(int i=2;i*i<=n;i++)
		if(n % i == 0)
			return false;
	return true;
}

int p[1000001];

int main()
{
	IO_OP;
	
	int n, ncp;
	cin >> n;
	ncp = n;
	if(isp(n) || n == 1) {
		cout << n << " " << 0 << endl;
		return 0;
	}
	int ans = 1;
	for(int i=2;i<=n;i++) {
		if(isp(i)) {
			if(n % i == 0)
				ans *= i;
			while(n % i == 0) {
				p[i]++;
				n /= i;
			}
		}
	}
	int mx = -1;
	for(int i=0;i<1000001;i++) {
		mx = max(mx, p[i]);
	}
	if(mx == 1) {
		cout << ncp << " " << 0 << endl;
		return 0;
	}
	int i, ad = 0;
	for(i=0;(1 << i) < mx;i++);
	for(int j=0;j<1000001;j++) {
		if(p[j] && p[j] != (1 << i)) {
			ad = 1;
			break;
		}
	}
	cout << ans << " " << i+ad << endl;
}