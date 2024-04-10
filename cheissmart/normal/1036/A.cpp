#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	if(k % n) {
		cout << k/n+1 << endl;
	} else {
		cout << k/n << endl;
	}
}