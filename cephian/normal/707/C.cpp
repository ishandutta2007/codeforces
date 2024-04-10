#include <iostream>

using namespace std;
typedef long long ll;

ll solve(ll k, ll mult = 1) {
	if(k == 1 || k == 2)
		cout << "-1\n";
	else if(k == 4)
		cout << 3*mult << " " << 5*mult << "\n";
	else if(k%2==0)
		solve(k/2,mult*2);
	else
		cout << (mult*(k*k-1))/2 << " " << (mult*(k*k+1))/2 << "\n"; 
}

int main() {
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	solve(n);
	return 0;
}