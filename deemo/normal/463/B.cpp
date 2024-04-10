#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, h[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> h[i];

	ll cur = -h[0];
	ll mini = cur;
	for (ll i = 1; i < n; i++){
		cur += (h[i - 1] - h[i]);
		mini = min(mini, cur);
	}
	cout << max(0LL, -mini) << "\n";
	return	0;
}