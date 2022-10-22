#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

long long n, k;

int main(){
	cin >> n >> k;
	if (n == 1){
		cout << "0" << endl;
		return 0;
	}
	n--;
	k--;
	if (n > k * (k + 1)/ 2)	cout << -1 << endl;
	else{
		ll b = 1, e = k, mid, ret = k + 1;
		while (b <= e){
			mid = (b + e)/ 2;
			ll sum = k * (k + 1)/ 2 - (mid - 1) * (mid)/ 2;
			if (sum <= n){
				ret = mid;
				e = mid - 1;
			}
			else b = mid + 1;
		}
		n -= k * (k + 1)/ 2 - (ret - 1) * ret / 2;
		if (n == 0)	cout << k - ret + 1 << endl;
		else	cout << k - ret + 2 << endl;
	}
	return 0;
}