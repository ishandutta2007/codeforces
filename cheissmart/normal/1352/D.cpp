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

const int INF = 1e9 + 7, N = 1003;

int A[N];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> A[i];
		int a = 0, b = 0;
		int la = 0, lb = 0, l = 0, r = n - 1;
		int move = 0;
		while(l <= r) {
			if(move & 1) { // bob
				int cur = 0;
				while(l <= r && cur <= la) {
					cur += A[r--];
				}
				lb = cur;
				b += cur;
			} else { // alice
				int cur = 0;
				while(l <= r && cur <= lb) {
					cur += A[l++];
				}
				la = cur;
				a += cur;
			}
			move++;
		}
		cout << move << " " << a << " " << b << endl;
	}
	
}