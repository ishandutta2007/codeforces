//  228

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <string>

#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
	if (a == 0 || b == 0)return abs(a - b);
	ll res = a % b;
	while (res) {
		a = b;
		b = res;
		res = a % b;
	}
	return b;
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
ll max(ll a, ll b) {
	if (a > b)return a;
	else return b;
}
ll min(ll a, ll b) {
	if (a < b)return a;
	else return b;
}
ll numberofdiviser(ll a) {
	ll ans = 0;
	ll i;
	for (i = 1; i * i < a; i++) {
		if (a % i == 0)ans += 2;
	}
	if (i * i == a)ans++;
	return ans;
}
void fival(ll * a, ll b, ll n) {
	for (int i = 0; i < n; i++) {
		a[i] = b;
	}
}
ll sum, ans, l, r, x;
ll ss(vector<ll> a, vector<ll>& b, int ii)
{
	for (int i = ii; i < a.size(); i++) {

		b.push_back(a[i]);
		sum += a[i];
		if (b.size() > 1 && sum >= l && sum <= r && b[b.size() - 1] - b[0] >= x)ans++;
		ss(a, b, i + 1);
		sum -= b[b.size() - 1];
		b.pop_back();
	}

	return ans;
}

int solve() {
	ll n, m, k; cin >> n >> m >> k;
	if (n % 2 == 0)return cout << 0, 0;
	ll sum = k * (m / ((n + 1) / 2));
	ll mm = 1000000;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i % 2 == 0)mm = min(mm, x);
	}
	cout << min(mm, sum);
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;//cin >> t;
	while (t--) {
		solve();
	}
}