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
	int horiz = 0, vert = 0;
	string s;
	cin >> s;
	for(auto& x : s) {
		if(x == '0') {
			cout << 1 << " " << vert%4+1 << endl;
			vert += 1;
		} else {
			cout << 3 << " " << horiz%4+1 << endl;
			horiz += 2;
		}
	}
	return 0;
}