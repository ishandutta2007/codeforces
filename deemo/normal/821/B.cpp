#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

ll get(ll x, ll y){
	ll temp = x*(x+1)/2;
	temp = (temp+(x+1)*y+temp)*(y+1)/2;
	return temp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, b;
	cin >> m >> b;
	ll ans = 0;
	for (int i = 0; i <= b; i++){
		ll x = 1ll*(b-i)*m;
		ans = max(ans, get(i, x));
	}
	cout << ans << "\n";
	return 0;
}