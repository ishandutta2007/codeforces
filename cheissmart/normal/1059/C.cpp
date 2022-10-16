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

void go(int n, int m) {
	if(n == 3) {
		cout << m << " " << m << " " << 3*m << " ";
		return;
	}
	if(n == 1) {
		cout << m << " ";
		return;
	}
	for(int i=1;i<=n;i+=2)
		cout << m << " ";
	go(n/2, m*2);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	go(n, 1);
	
}