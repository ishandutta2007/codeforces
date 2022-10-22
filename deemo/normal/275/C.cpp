#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;

ll n, k;
ll vec[MAXN];
map<ll, bool>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);

	int ans = 0;
	for (int i = 0; i < n; i++){
		ll x = vec[i];
		if (mp[x])	continue;
		ans++;
		mp[x * k] = 1;
	}
	cout << ans << endl;
	return 0;
}