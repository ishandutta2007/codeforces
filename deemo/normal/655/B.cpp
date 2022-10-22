#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	
	ll ans = 0;
	for (int i = 0; i < k && i < n/2; i++)
		ans += (2 * ((n - 2 * i) - 1)) - 1;
	cout << ans << "\n";
	return	0;
}