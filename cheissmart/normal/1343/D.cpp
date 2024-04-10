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

int a[N];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vi psum(2*k+2);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n / 2; i++) {
			int x = a[i], y = a[n-i-1];
			if(x > y) swap(x, y);
			int l = x + 1, r = y + k;
			psum[1]+=2, psum[2*k+1]-=2;
			psum[l]--, psum[r+1]++;
			psum[x+y]--, psum[x+y+1]++;
		}
		int mn = INF;
		for(int i=1;i<=2*k;i++) {
			psum[i] += psum[i-1];
			mn = min(mn, psum[i]);
		}
		cout << mn << endl;
	}	
	
}