#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	
	ll a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	ll count[n];
	ll countSum;
	
	ll lo = -4 * 1000000000000000000L;
	ll hi = 10000000000L;
	while (hi - lo > 1){
		ll crit = lo + ((hi - lo)/2);
		countSum = 0;
		for(int i = 0; i < n; i++){
			ll lo2 = -1;
			ll hi2 = a[i];
			while (hi2 - lo2 > 1){
				ll b = lo2 + ((hi2 - lo2)/2);
				ll diff = a[i] - 3*b*b - 3*b - 1;
				if (diff < crit){
					hi2 = b;
				}
				else{
					lo2 = b;
				}
			}
			count[i] = hi2;
			countSum += hi2;
		}
		
		if (countSum <= k){
			hi = crit;
		}
		else{
			lo = crit;
		}
	}
	
	ll crit = lo;
	countSum = 0;
	for(int i = 0; i < n; i++){
		ll lo2 = -1;
		ll hi2 = a[i];
		while (hi2 - lo2 > 1){
            ll b = lo2 + ((hi2 - lo2)/2);
            if (b > 1000000000) cout << b << " " << i << " " << a[i] << endl;
			ll diff = a[i] - 3*b*b - 3*b - 1;
			if (diff <= crit){
				hi2 = b;
			}
			else{
				lo2 = b;
			}
		}
		count[i] = hi2;
		countSum += hi2;
	}
	
	ll extra = k - countSum;
	for(int i = 0; (i < n) && (extra > 0); i++){
		ll b = count[i];
		if (a[i] - 3*b*b - 3*b - 1 == crit){
			count[i] += 1;
			extra -= 1;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << count[i] << " ";
	}
	
	return 0;
}