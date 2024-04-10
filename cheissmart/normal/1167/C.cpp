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

int p[500005], h[500005], sz[500005];

int init(int n) {
	for(int i=1;i<=n;i++) {
		p[i] = i;
		sz[i] = 1;
	}
}

int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	if(h[rx] > h[ry]) {
		p[ry] = rx;
		sz[rx] += sz[ry];
	}
	else {
		p[rx] = ry;
		sz[ry] += sz[rx];
		if(h[rx] == h[ry])
			h[ry]++;
	}
}

int a[500005];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	init(n);
	for(int i=0;i<m;i++) {
		int k;
		cin >> k;
		for(int j=0;j<k;j++)
			cin >> a[j];
		for(int j=1;j<k;j++)
			unite(a[j], a[j-1]);
	}
	for(int i=1;i<=n;i++)
		cout << sz[find(i)] << " ";
}