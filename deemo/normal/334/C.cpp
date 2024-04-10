#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll x;

int main(){
	cin >> x;
	ll t = 1;
	while (x % t == 0)	t *= 3;
	cout << x / t + 1 << endl;
	return 0;	
}