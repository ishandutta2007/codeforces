#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	cout << fixed << setprecision(12);
	ll n;	cin >> n;
	ll foo = 0, bar = 0, baz = 0, quz = 1;
	for (ll i = n; i; i--){
		ll pur;	cin >> pur;
		foo += pur;
		bar++;

		if (max(foo * quz, bar * baz) == foo * quz){
			baz = foo;
			quz = bar;
		}
	}
	ld ret = baz;
	ret /= ld(quz);
	cout << ret << endl;
	return 0;
}