#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, k, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> a[i];
	int mn = *min_element(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int dif = a[i] - mn;
		if (dif % k){
			cout << "-1\n";
			return 0;
		}
		ans += dif/k;
	}
	cout << ans << endl;
	return 0;
}