#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll n;	cin >> n;
	ll s = 0, t = 1;
	while (s + t < n)	s += t++;
	cout << n - s << "\n";
	return	0;
}