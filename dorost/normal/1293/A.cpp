#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t;
	cin >> t;
	while (t--){
		ll n, m , k;
		cin >> n >> m >> k;
		ll a[k];
		for (int i = 0; i < k; i++){
			cin >> a[i];
		}
		for (int i = 0; true; i++){
			ll x;
			if(i % 2){
				x = (max (1ll, m - i / 2));
			}else{
				x = min(m + i / 2, n);
			}
			bool f = true;
			for (int j = 0; j < k; j++){
				if(x == a[j]){
					f = false;
					break;
				}
			}
			if (f){
				cout << i / 2 << endl ;
				break;
			}
		}
	}
}