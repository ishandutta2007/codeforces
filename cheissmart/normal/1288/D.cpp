#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("Ofast,no-stack-protector","unroll-loops")
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

const int INF = 1e9 + 7, N = 3e5, M = 8;

pi pre[1<<M];
int a[N][M], lst[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	for(int i=0;i<n;i++) {
		for(int j=0;j<(1<<m);j++) {
			int mn = INF;
			for(int k=0;k<m;k++)
				if(j >> k & 1)
					mn = min(mn, a[i][k]);
			pre[j] = max(pre[j], MP(mn, i));
		}
	}
	int ans = -INF, x=0, y=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			int bit = 0;
			for(int k=0;k<m;k++) {
				if(a[i][k] < a[i][j])
					bit |= 1 << k;
			}
			if(bit == 0) {
				if(a[i][j] > ans) {
					ans = a[i][j];
					x = i;
					y = i;
				}
				continue;
			} else {
				if(pre[bit].F >= a[i][j] && a[i][j] > ans) {
					ans = a[i][j];
					x = i;
					y = pre[bit].S;
				}
			}
		}
	}
	cout <<x+1 << " " << y+1 << endl;
	
}