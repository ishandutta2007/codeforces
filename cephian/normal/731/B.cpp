#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,a[N]={0};

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i <= n; ++i) {
		if(a[i] < 0)  {
			cout << "NO\n";
			return 0;
		}
		if(a[i]&1) {
			--a[i+1];
		}
	}
	cout << "YES\n";
	return 0;
}