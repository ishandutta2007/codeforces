#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 3e3;
const ll N = 1000;

ll n;
ll c1[MAXN];
ll c2[MAXN];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--){
		ll a, b;	cin >> a >> b;
		c1[a + b]++;
		c2[(N - b + 1) + a]++;
	}
	for (ll i = 0; i < MAXN; i++)
		ans += c1[i] * (c1[i] - 1)/2, ans += c2[i] * (c2[i] - 1)/ 2;
	cout << ans << endl;
	return	0;
}