#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
int query(int x)
{
	cout << "? " << x << endl;
	cin >> x;
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	
	int l = 1, r = 1 << 22;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(query(mid) != 1) l = mid + 1;
		else r = mid;
	}
	LL ans = r;
	rep1(i, n) {
		int h = query(r / i);
		if(h != 0) ans = min(ans, 1LL * r / i * h);
	}
	cout << "! " << ans << endl;
	return 0;
}