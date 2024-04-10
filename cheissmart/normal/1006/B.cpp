#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

pi a[2048];
int b[2048];

int main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> a[i].F;
		a[i].S = i;
		b[i] = a[i].F;
	}
	sort(a, a+n);
	reverse(a, a+n);
	vi v;
	int ans = 0;
	v.PB(-1);
	for(int i=0;i<k;i++) {
		ans += a[i].F;
		v.PB(a[i].S);
	}
	cout << ans << endl;
	sort(v.begin(), v.end());
	for(int i=1;i<k;i++) {
		cout << v[i] - v[i-1] << " ";
	}
	cout << n - v[k-1]-1 << endl;
}