#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 10;
const ll INF = 6e18;

int n;
ll c, x[MAXN], y[MAXN];

ll get(ll z){
	ll ret = n;
	for (int i = 0; ret <= c && i < n; i++){
		ll a = x[i], b = y[i];
		if (a == 0)	continue;
		if (INF /z < a) return INF;
		ll temp = z * a;
		ret += temp/b;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> c;
	if (c < n){
		cout << "0\n";
		return 0;	
	}

	ll cc = 0;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i], cc += x[i];
	if (cc == 0){
		if (c > n)
			cout << "0\n";
		else
			cout << -1 << "\n";
		return 0;
	}

	ll b = 1, e = 2e18, l = 0;
	while (b <= e){
		ll mid = (b + e)/2;
		if (get(mid) < c)
			l = mid, b = mid + 1;
		else
			e = mid - 1;
	}

	b = 1, e = 2e18;
	ll r = 2e18;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (get(mid) > c)
			r = mid, e = mid - 1;
		else
			b = mid + 1;
	}

	cout << max(0LL, r - l - 1) << endl;
	return 0;
}