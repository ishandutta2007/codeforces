#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, m;	cin >> n >> m;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		int z = 5 - i % 5;
		z %= 5;
		
		ans += m/5;
		int t = m % 5;
		if (z && t >= z)
			ans++;
	}
	cout << ans << endl;
	return 0;
}