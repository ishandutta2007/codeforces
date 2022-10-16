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

int a[1003], b[1003], h;

bool ok(int m) {
	for(int i=0;i<m;i++)
		b[i] = a[i];
	sort(b, b+m, greater<int>());
	ll s = 0;
	for(int i=0;i<m;i+=2)
		s += b[i];
	return s <= h;
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n >> h;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int l = 1, r = n;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) l = m + 1;
		else r = m - 1;
	}
	cout << r << endl;
}