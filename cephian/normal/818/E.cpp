#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
ll A[N][20]={};
int n,a;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a;
	for(int i = 0; i < n; ++i) {
		cin >> A[i][0];
		A[i][0] %= a;
	}
	A[n][0] = 1;
	for(int k = 1; k < 20; ++k) {
		for(int i = 0; i <= n; ++i) {
			A[i][k] = A[i][k-1]*A[min(i+(1<<(k-1)),n+1)][k-1]%a;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		int j = i;
		if(A[i][0] != 0) {
			++j;
			ll pr = A[i][0];
			for(int d = 19; d >= 0; --d) {
				// cout << j << "," << d << "," << (pr*A[j][d])%a << endl;
				if((pr*A[j][d])%a != 0 && j+(1<<d) <= n+1) {
					// cout << "on " << i << ", moving " << j << " -> " << (j+(1<<d)) << endl;
					pr = pr*A[j][d]%a;
					j += 1<<d;
				}
			}
		}
		if(j == n+1) continue;
		ans += (n-j);
	}
	cout << ans << "\n";
}