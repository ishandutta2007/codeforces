#include <iostream>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	if(k == 1) 
		cout << n << endl;
	else {
		long long ans = 1;
		while(ans < n)
			ans = ans * 2 + 1;
		cout << ans << endl; // 2^(p+1) - 1
	}
}