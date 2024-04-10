#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

int main(){
	int n;	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += (n - i - 1) * (i + 1) + 1;
	cout << ans << endl;
	return 0;
}