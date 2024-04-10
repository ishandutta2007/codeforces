#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--){
		ll n; cin >> n;
		if (n == 1)
			cout << "0\n";
		else{
			ll lo = 0, hi = n-1;
			while (hi-lo>1){
				ll mid = hi+lo>>1;
				ll rem = n - mid;
				ll temp = 1ll*rem*(rem-1)/2;
				if (temp > mid)
					lo = mid;
				else
					hi = mid;
			}
			cout << max(lo+min(lo, 1ll*(n-lo)*(n-lo-1)/2), hi+min(hi, 1ll*(n-hi)*(n-hi-1)/2)) << "\n";
		}
	}
	return 0;
}