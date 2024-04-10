#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

ld get(ll a, ll b){
	if (b == 0)	return	1;
	if (a == 0)	return	0;
	ld tot = a * b;
	if (4 * b <= a){
		ld ret = b * 2 * b;
		ret = tot - ret;
		return	ret/ tot;
	}
	
	ld ret = (ld(a)/ ld(8)) * a;
	return ret/tot;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll te;	cin >> te;
	cout << fixed << setprecision(12);
	while (te--){
		ll a, b;	cin >> a >> b;
		cout << ld(0.5) + (get(a, b) * 0.5) << "\n";
	}
	return	0;
}