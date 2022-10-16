#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;

	int n, mx1 = 0, mx2 = 0;
	cin >> n;
	while(n--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		if(x > y) swap(x, y);
		if(c == '+') {
			mx1 = max(mx1, x);
			mx2 = max(mx2, y);
		} else {
			if(x >= mx1 && y >= mx2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
 		}
	}
}