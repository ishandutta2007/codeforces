#include<iostream>
#include<algorithm>

using namespace std;

int n, m, l, r;

int main(){
	cin >> n >> m >> l >> r;	l--, r--;
	if (l/m == r/m)	cout << 1 << endl;
	else if (l/m + 1 == r/m)	cout << 2 - bool(bool(r == n - 1 || (r + 1) % m == 0) && l % m == 0)<< endl;
	else{
		if (l % m - 1 == r % m)	cout << 2 << endl;
		else cout << 3 - bool((r + 1) % m == 0 || r == n - 1) - bool(l % m == 0)<< endl;
	}
	return	0;
}