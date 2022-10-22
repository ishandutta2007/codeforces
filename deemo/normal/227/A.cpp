#include<iostream>
#include<cmath>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;

int main(){
	pair<ll, ll>	a, b, c;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	ll t = ll((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first));
	if (t == 0)
		cout << "TOWARDS\n";
	if (t > 0)
		cout << "LEFT\n";
	if (t < 0)
		cout << "RIGHT\n";
	return 0;
}