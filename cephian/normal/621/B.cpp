#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int n;
int d1[5005]={0};
int d2[5005]={0};

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	ll a = 0;
	for(int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		a += d1[x+y+2000];
		a += d2[x-y+2000];
		++d1[x+y+2000];
		++d2[x-y+2000];
	}
	cout << a << "\n";

	return 0;
}