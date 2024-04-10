#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 10000 + 10;

int n, cnt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		cnt[a]++;
		cnt[b]++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += cnt[i] * (cnt[i] - 1) / 2;
	cout << ans << endl;
	return 0;
}