#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define FORv(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define tr static_cast
typedef long long int ll;
typedef unsigned long long int ull;
const ll MOD = 1000000007;
const int INF = 2000000000;

ll f(ll x){
	return x * (x + 1) / 2;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long x;
	cin >> n >> x;
	vector<ll> d(n + 1);
	for (int i = 1; i < n + 1; i++){
		cin >> d[i];
	}
	for (int i = 1; i < n + 1; i++){
		d.pb(d[i]);
	}
	vector<ll> one(2 * n + 1, 0);
	vector<ll> two(2 * n + 1, 0);
	for (int i = 1; i < 2 * n + 1; i++){
		one[i] = one[i - 1] + d[(i % n == 0 ? n : i % n)];
		two[i] = two[i - 1] + f(d[(i % n == 0 ? n : i % n)]);
	}
	ll ans = -1;
	for (int i = n + 1; i <= 2 * n; i++){
		int ptrl = 0, ptrr = i;
		int ptrwant = -1;
		ll manque = 0;
		while (ptrl != ptrr){
			int check = ptrr + ptrl;
			if (check % 2 == 1){
				check--;
			}
			check /= 2;
			if (one[i] - one[check] > x){
				ptrl = check + 1;
			}
			else if (one[i] - one[check] < x){
				ptrr = check;
				manque = x - one[i] + one[check];
			}
			else {
				ptrwant = check;
				manque = 0;
				break;
			}
			if (ptrr == ptrl){
				ptrwant = ptrl;
				manque = x - one[i] + one[ptrr];
				break;
			}
		}
		ll temp = two[i] - two[ptrwant];
		temp += (2 * d[ptrwant] + (manque - 1) * (-1)) * manque / 2;
		if (temp >= ans){
			ans = temp;
		}
	}
	cout << ans << "\n";
	return 0;
}