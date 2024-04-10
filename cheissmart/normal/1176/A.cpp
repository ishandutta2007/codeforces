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

	int q;
	cin >> q;
	while(q--) {
		ll n;
		cin >> n;
		int a = 0, b = 0, c = 0;
		while(n % 2 == 0) n /= 2, a++;
		while(n % 3 == 0) n /= 3, b++;
		while(n % 5 == 0) n /= 5, c++;
		if(n != 1) cout << -1 << endl;
		else cout << a + 2 * b + 3 * c << endl;
	}

}