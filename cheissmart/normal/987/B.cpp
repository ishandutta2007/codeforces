#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int x, y;
	cin >> x >> y;
	if(x == y) {
		cout << "=" << endl;
		return 0;
	}
	if(x <= 10 && y <= 10) {
		int a = 1, b = 1;
		for(int i=0;i<y;i++) a *= x;
		for(int i=0;i<x;i++) b *= y;
		if(a > b) cout << ">" << endl;
		else if(a < b) cout << "<" << endl;
		else cout << "=" << endl;
	} else {
		if(x == 1) cout << "<" << endl;
		else if(y == 1) cout << ">" << endl;
		else {
			if(x < y) cout << ">" << endl;
			else cout << "<" << endl;
		}
	}
	
}