#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int ok[105];

int main()
{
	IO_OP;
	
	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;
	for(;;) {
		if(a == b) {
			cout << "YES" << endl;
			return 0;
		}
		if(b == y) break;
		if(b != 1) b--;
		else b = n;
		if(a == x) break;
		if(a != n) a++;
		else a = 1;
	}
	cout << "NO" << endl;
}