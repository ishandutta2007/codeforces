#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[200005], b[200005];
int n, m, ta, tb, k;

bool ok(int x) {
	if(k >= x) return true;
	for(int i=0;i<=k;i++) {
		int s = a[i+1];
		int d = k - i;
		if(b[x - d] < s) return true;
	}
	return false;
}

int32_t main()
{
	IO_OP;
	
	cin >> n >> m >> ta >> tb >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		a[i] += ta;
	}
	for(int i=1;i<=m;i++)
		cin >> b[i];
	if(k >= n || k >= m) {
		cout << -1 << endl;
		return 0;
	}
	int l = 1, r = m;
	while(l <= r) {
		int mm = (l + r) / 2;
		if(ok(mm)) l = mm + 1;
		else r = mm - 1;
	}
	if(l <= m)
		cout << b[l] + tb << endl;
	else
		cout << -1 << endl;
	
}