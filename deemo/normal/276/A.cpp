#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int n, k;	cin >> n >> k;
	int ans = -1e9;
	while (n--){
		int a, b;	cin >> b >> a;
		int t = b;
		if (a > k)
			t -= (a - k);
		ans = max(ans, t);
	}
	cout << ans << endl;
	return 0;
}