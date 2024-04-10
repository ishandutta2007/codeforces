#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 998244353;

int ct[13], a[13][100005], b[13][100005];

int32_t main()
{
	IO_OP;
	
	int n, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int tt;
		cin >> tt;
		ct[to_string(tt).size()]++;
		for(int j=1;j<12;j++) {
			int p = 1, l = j;
			int t = tt;
			while(t) {
				int d = t % 10;
				t /= 10;
				a[j][i] += p * d % M; a[j][i] %= M;
				p *= 10; p %= M;
				if(l) {
					p *= 10; p %= M;
					l--;
				}
			}
		}
		for(int j=1;j<12;j++) {
			int p = 1, l = j;
			int t = tt;
			while(t) {
				if(l) {
					p *= 10; p %= M;
					l--;
				}
				int d = t % 10;
				t /= 10;
				b[j][i] += p * d % M; b[j][i] %= M;
				p *= 10; p %= M;
			}
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=1;j<12;j++) {
			ans += (ct[j]) * a[j][i] % M;
			ans %= M;
		}
		for(int j=1;j<12;j++) {
			ans += (ct[j]) * b[j][i] % M;
			ans %= M;
		}
	}
	cout << ans << endl;
}