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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		if(n-(k-1) > 0 && ((n-(k-1))&1)) {
			cout << "YES" << endl;
			for(int i = 0; i < k - 1; i++) cout << 1 << " ";
			cout << n - (k - 1) << endl;
		} else if(n-(k-1)*2 > 0 && ((n-(k-1)*2)&1)==0){
			cout << "YES" << endl;
			for(int i = 0; i < k - 1; i++) cout << 2 << " ";
			cout << n-(k-1)*2 << endl;
		} else {
			cout << "NO" << endl;
		}
	 }
	
}