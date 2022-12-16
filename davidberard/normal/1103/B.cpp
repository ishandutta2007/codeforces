#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main () {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while(true) {
		string s;
		cin >> s;
		if(s[0] == 'm' || s[0] == 'e') {
			return 0;
		} else if(s[0] != 's') {
			assert(false);
		}
		int x = 0;
		int y = 1;
		bool status = false;
		while(y < 1e9) {
			cout << "? " << x << " " << y << endl;
			cin >> s;
			if(s[0] != 'y') {
				status = true;
				break;
			}
			x = y;
			y = y*2+1;
		}
		if(!status) {
			y = 1e9;
		}
		--y;
		while(x < y) {
			int m = (x+y+1)/2;
			cout << "? " << x << " " << m << endl;
			cin >> s;
			if(s[0] != 'y') {
				y = m-1;
			} else {
				x = m;
			}
		}
		cout << "! " << x+1 << endl;
	}
	return 0;
}