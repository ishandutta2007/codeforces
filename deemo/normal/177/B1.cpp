#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n;	cin >> n;
	ll ans = n;
	for (int i = 2; i * i <= n;)
		if (n % i == 0)
			n/=i, ans += n;
		else
			i++;
	if (n > 1)
		ans++;
	cout << ans << endl;
	return 0;
}