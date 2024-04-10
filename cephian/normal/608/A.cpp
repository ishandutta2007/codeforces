#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,s;
	cin >> n >> s;
	int fastest = s;
	for(int i = 0; i < n; ++i) {
		int a,b;
		cin >> a >> b;
		fastest = max(fastest,a+b);
	}
	cout << fastest << "\n";
}