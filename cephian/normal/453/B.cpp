#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
vector<int> mask;

int dp[100][1<<17],c[100][1<<17],a[100],n;

vector<int> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i = 0; i < 59; ++i) {
		int msk = 0;
		for(int j = 0; j < primes.size(); ++j)
			if(i%primes[j] == 0)
				msk ^= (1<<j);
		mask.push_back(msk);
	}

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		for(int m = (1<<17)-1; m >= 0; --m) {
			dp[i][m] = 0x7fffffff;
			for(int k = 1; k < 59; ++k) {
				if((mask[k]|m) == m) {
					int w = ((i)?dp[i-1][m^mask[k]]:0) + abs(a[i]-k);
					if(w < dp[i][m]) {
						dp[i][m] = w;
						c[i][m] = k;
					}
				}
			}
		}
	}

	int b = 0;
	for(int m = (1<<17)-1; m > 0; --m) {
		if(dp[n-1][m] < dp[n-1][b])
			b = m;
	}
	for(int i = n-1; i >= 0; --i) {
		ans.push_back(c[i][b]);
		b ^= mask[c[i][b]];
	}
	for(int i = n-1; i >= 0; --i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}