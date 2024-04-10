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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int r, c;
	cin >> r >> c;
	if(r == 1 && c == 1) {
		cout << 0 << endl;
		return 0;
	}
	if(r == 1) {
		for(int i=2;i<=c+1;i++) cout << i << " ";
		return 0;
	}
	if(c == 1) {
		for(int i=2;i<=r+1;i++) cout << i << endl;
		return 0;
	}
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cout << i * (j + r) << " \n"[j == c];

}