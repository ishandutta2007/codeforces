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

int pw[100];
int bb[] = {0, 2, 3, 1};
int cc[] = {0, 3, 1, 2};

array<int, 3> get(int n) {
	for(int len = 0; len < 100; len++) {
		int has = pw[len];
		if(has <= n) n -= has;
		else {
			int tt = n;
			int a = pw[len] + tt;
			int b = 2 * pw[len];
			for(int j=28;j>=0;j--) {
				b += bb[(tt % pw[j+1]) / pw[j]] * pw[j];
			}
			int c = 3 * pw[len];
			for(int j=28;j>=0;j--) {
				c += cc[(tt % pw[j+1]) / pw[j]] * pw[j];
			}
			return {a, b, c};
		}
	}
}

signed main()
{
	IO_OP;
	
	pw[0] = 1;
	for(int i=1;i<100;i++) pw[i] = pw[i-1] * 4;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int tt = (n - 1) / 3;
		cout << get(tt)[(n-1) % 3] << endl;
	}
	
}