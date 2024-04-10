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

int a[128];

int main()
{
	IO_OP;

	int n, k, c = 0, d = 0;
	cin >> n >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i] == 1) c++;
		else d++;
	}
	int mx = -1;
	for(int i=1;i<=k;i++) {
		int u = 0, v = 0;
		for(int j=i;j<=n;j+=k)
			if(a[j] == 1) u++;
			else v++;
		u = c - u;
		v = d - v;
		mx = max(mx, abs(u-v));
	}
	cout << mx << endl;
}