#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	long long n;	cin >> n;
	if (n >= 0)	cout << n << endl;
	else{
		ll a = n/10;
		ll b = (a/10) * 10 + (n % 10);
		if (b > 0)	b = -b;
		cout << max(a, b) << endl;
	}
	return 0;
}