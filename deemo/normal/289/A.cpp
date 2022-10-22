#include<iostream>

using namespace std;

int main(){
	int n;	cin >> n;
	int k;	cin >> k;
	int sum = 0;
	for (int i = 0; i < n; i++){
		int l, r;	cin >> l >> r;
		sum += r - l + 1;
	}
	int ans = sum % k;
	ans = k - ans;
	ans %= k;
	cout << ans << endl;
	return 0;
}