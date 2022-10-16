#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ll sum = 0;
		int k = __lg(a[i]) + 1;
		for(int j = i + 2; j < n; j++) {
			sum += a[j - 1];
			if(sum >= (1 << k)) break;
			if((a[i] ^ a[j]) == sum) {
				if(a[i] > a[j]) ans++;
			}
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		ll sum = 0;
		int k =__lg(a[i]) + 1;
		for(int j = i - 2; j >= 0; j--) {
			sum += a[j + 1];
			if(sum >= (1 << k)) break;
			if((a[i] ^ a[j]) == sum) {
				if(a[i] >= a[j])
					ans++;
			}
		}
	}
	cout << ans << endl;

}