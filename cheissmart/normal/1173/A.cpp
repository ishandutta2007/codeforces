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

int main()
{
	IO_OP;
	
	int x, y, z;
	cin >> x >> y >> z;
	int a1 = x - y + z, a2 = x - y - z;
	if(a1 > 0 && a2 > 0) {
		cout << "+" << endl;
	} else if(a1 < 0 && a2 < 0) {
		cout << "-" << endl;
	} else if(a1 == 0 && a2 == 0) {
		cout << "0" << endl;
	} else {
		cout << "?" << endl;
	}
	
}