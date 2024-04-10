#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

pi a[5003];
int p[5003][5003], b[5003];

int main()
{
	IO_OP;
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=q;i++) {
		int l, r;
		cin >> l >> r;
		b[l]++, b[r+1]--;
		a[i] = {l, r};
	}
	sort(a+1, a+q+1);
	int tot = 0, mx = 0;
	for(int i=1;i<=q;i++) {
		tot += max(0, a[i].S - max(mx, a[i].F)+1);
		mx = max(mx, a[i].S+1);
	}
	for(int i=1;i<=n;i++)
		b[i] += b[i-1];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			p[i][j] = p[i][j-1];
			if(b[j] == i) p[i][j]++;
		}
	}
	int ans = 0;
	for(int i=1;i<=q;i++) {
		for(int j=i+1;j<=q;j++) {
			if(a[i].S < a[j].F) {
				ans = max(ans, tot - ((p[1][a[i].S]-p[1][a[i].F-1]) + (p[1][a[j].S]-p[1][a[j].F-1])));
			}
			else{
				ans = max(ans, tot - ((p[1][a[i].S]-p[1][a[i].F-1]) + (p[1][a[j].S]-p[1][a[j].F-1]) + (p[2][min(a[i].S, a[j].S)] - p[2][max(a[j].F, a[i].F)-1])));
			}
		}
	}
	cout << ans << endl;
}