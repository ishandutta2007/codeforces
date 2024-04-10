#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, x, vec[MAXN], ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec, vec + n);
	for (ll i = 0; i < n; i++){
		ans += vec[i] * x;
		x = max(1LL, x - 1);
	}
	cout << ans << endl;
	return	0;
}