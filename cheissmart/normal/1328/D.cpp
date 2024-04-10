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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], b[N];

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		int cnt = 0;
		for(int i=0;i<n;i++) if(a[i] != a[(i+1)%n]) cnt++;
		if(cnt == 0) {
			cout << 1 << endl;
			for(int i=0;i<n;i++) cout << 1 << ' ';
			cout << endl;
		} else {
			if(n % 2 == 0) {
				cout << 2 << endl;
				for(int i=0;i<n;i++) cout << (i&1) + 1 << ' ';
				cout << endl;
			} else {
				if(cnt == n) {
					cout << 3 << endl;
					cout << 3 << " ";
					for(int i=1;i<n;i++) cout << (i&1) + 1 << ' ';
					cout << endl;
				} else {
					cout << 2 << endl;
					int j;
					for(j=0;j<n;j++) if(a[j] == a[(j+1)%n]) break;
					b[j] = 2, b[(j+1)%n] = 2;
					int k = (j + 2) % n, cur = 1;
					for(int i=0;i<n-2;i++) {
						b[k] = cur;
						cur ^= 3;
						k = (k + 1) % n;
					}
					for(int i=0;i<n;i++) cout << b[i] << " ";
					cout << endl;
				}
			}
		}
	}	
	
}