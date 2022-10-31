#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if((i+j)%2 == 0)
				cout << "B";
			else cout << "W";
		}
		cout << '\n';
	}
}