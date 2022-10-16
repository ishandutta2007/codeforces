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
	
	int n;
	cin >> n;

	if(n <= 5) {
		cout << -1 << endl;
	} else {
		cout << "1 2" << endl;
		int l = (n-2)/2;
		for(int i=3;i<3+l;i++)
			cout << 1 << " " << i << endl;
		for(int i=3+l;i<=n;i++)
			cout << 2 << " " << i << endl;
	}

	for(int i=1;i<n;i++)
		cout << i << " " << i + 1 << endl;	
	
}