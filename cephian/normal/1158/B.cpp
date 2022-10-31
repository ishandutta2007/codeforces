#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	if(n%2 != k%2) return 0;
	string s(n, '0');
	// we can repeat 2x
	if (k == 1) {
		s[0] = '1';
		cout << s << '\n';
	} else if ((k-2)*3 + 2 <= n) {
		s[k-2] = '1';
		s[2*(k-1)-1] = '1';
		cout << s << '\n';
	} else if(n == k) {
		cout << s << '\n';
	} else {
		int r = (n-k)/2;
		for(int i = r; i < n; i += r+1) {
			s[i] = '1';
		}
		cout << s << '\n';
	}

}