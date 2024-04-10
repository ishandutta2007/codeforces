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
 
int cnt = 0;
 
bool ok (int m){
	cnt++;
	cout << "> " << m << endl;
	int res;
	cin >> res;
	return res;
}
 
int a[1000006];
 
signed main()
{	
	int n;
	cin >> n;
	int l = 0, r = 1e9;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) l = m + 1;
		else r = m - 1;
	}
	int mx = l;
	for(int i=1;i<=n;i++) a[i] = i;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(a+1, a+n+1, rng);
	int j = 1, d = 0;
	while(cnt < 60 && j <= n) {
		int t = a[j++];
		cout << "? " << t << endl;
		int res;
		cin >> res;
		d = __gcd(d, mx - res);
		cnt++;
	}
	int x1 = mx - (n - 1) * d;
	cout << "! " << x1 << " " << d << endl;
}