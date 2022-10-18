

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ tc, n, m;
str a;

int main() {

	cin >> tc;
	for(; tc--; ) {
		cin >> n >> m >> a;
		str b = a;
		reverse(b.begin(), b.end());
		puts(!m || a == b ? "1" : "2");
	}

	return 0;
}