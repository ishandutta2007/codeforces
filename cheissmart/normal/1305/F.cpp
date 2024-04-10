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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], n;

int goo(int x) {
	int ret = 0;
	for(int i=0;i<n;i++) {
		if(a[i] < x) {
			ret += x - a[i];
		} else {
			int t = a[i] % x;
			ret += min(t, x - t);
		}
	}
	return ret;
}

int go(int x) {
	int ret = INF;
	for(int i=2;i*i<=x;i++) {
		if(x % i == 0) {
			while(x % i == 0) x /= i;
			ret = min(ret, goo(i));
		}
	}
	if(x != 1) ret = min(ret, goo(x));
	return ret;
}

signed main()
{
	IO_OP;
	
	mt19937 rng(time(0));
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	shuffle(a, a+n, rng);
	int ans = INF;
	for(int i=0;i<50;i++) {
		if(a[i] > 2) ans = min(ans, go(a[i]-1));
		if(a[i] > 1)ans = min(ans, go(a[i]));
		ans = min(ans, go(a[i]+1));
	}
	cout << ans << endl;
}