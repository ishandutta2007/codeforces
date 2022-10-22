#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	ll a, b, ans = 0;
	cin >> a >> b;
	if(max(a,b) % min(a, b) == 0){
		cout << max(a,b) / min(a, b);
		return 0;
	}	
	do{
		if (max(a,b) % min(a, b) == 0){
			ans += max(a, b) / min(a, b);
			break;
		}
		ans += max(a, b) / min(a, b);
		if(a > b)
			swap(a, b);
		if(min(a, b) <= 1)
			break;
		b %= a;
	}while(1);
	cout << ans;
}