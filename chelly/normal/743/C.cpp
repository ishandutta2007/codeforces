#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if(n != 1) {
		cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;
	}else {
		cout << -1 << endl;
	}
}