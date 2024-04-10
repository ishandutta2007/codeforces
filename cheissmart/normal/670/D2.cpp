#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int int64_t

using namespace std;

const int N = 100005;

int a[N], b[N];
int n, k;

bool ok(int m) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		ct += max(0LL, a[i]*m-b[i]);
		if(ct > k) return false;
	}
	return true;
}

int32_t main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	int l = 0, r = 2000000000;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) {
			l = m+1;
		} else {
			r = m-1;
		}
	}
	cout << r << endl;
	
}