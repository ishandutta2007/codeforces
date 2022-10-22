#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const ll INF = 1e18;

ll x, y, p, q;

bool check(ll mid){
	if (mid * q < y) return false;
	ll rem = mid*q - y;
	return mid * p >= x && mid * p - rem <= x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		cin >> x >> y >> p >> q;
		if (p == 0) q = 1;

		if (p == 0){
			if (x == 0)
				cout << "0\n";
			else
				cout << "-1\n";
		}
		else if (p == q){
			if (x == y)
				cout << "0\n";
			else
				cout << "-1\n";
		}
		else{
			ll lo = 0, hi = 2e9;
			while (hi-lo>1){
				ll mid = hi+lo>>1;
				if (check(mid))
					hi = mid;
				else
					lo = mid;
			}
			cout << hi*q-y << "\n";
		}
	}
	return 0;
}