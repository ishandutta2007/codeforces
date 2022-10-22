#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	ll n, cnt0 = 0, cnt1 = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		ll x;
		cin >> x;
		if(x == 0)
			cnt0 ++;
		if(x <= 0){
			cnt1++;
			ans += abs(x + 1);
		}else{
			ans += x - 1;
		}
	}
	if(cnt1 % 2)
		cout << ans + (cnt0 ? 0 : 2);
	else
		cout << ans;
}