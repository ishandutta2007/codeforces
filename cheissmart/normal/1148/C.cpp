#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

pi a[300005];
int b[300005], g[300005], ig[300005];
vector<pi> v;

void myswap(int i, int j) {
	v.PB({i, j});
//	cout << i << ", " << j << endl;
	swap(g[ig[i]], g[ig[j]]);
	swap(ig[i], ig[j]);
	swap(b[i], b[j]);
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i].F;
		a[i].S = i;
		b[i] = a[i].F;
		g[i] = ig[i] = i;
	}
	sort(a+1, a+n+1);
	for(int ii=1;ii<=n;ii++) {
		int i = ii;
		int j = g[a[i].S];
		if(i > j) swap(i, j);
		// swap i with j
		if(j == i) continue;
		if(j - i >= n / 2) {
			myswap(i, j);
		} else if(i > n/2 && j > n/2) {
			myswap(j, 1);
			myswap(1, i);
			myswap(j, 1);
		} else {
			if(j <= n/2) {
				myswap(j, n);
				myswap(n, i);
				myswap(j, n);
			} else {
				myswap(i, n);
				myswap(1, j);
				myswap(1, n);
				myswap(i, n);
				myswap(1, j);
			}
		}
	}
	cout << v.size() << endl;
	for(pi p:v)
		cout << p.F << " " << p.S << endl;
}