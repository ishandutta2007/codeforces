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

int n, z, a[200005];

bool ok(int k) {
	for(int i=0;i<k;i++) 
		if(a[n-k+i] - a[i] < z)
			return false;
	return true;
}

int main()
{
	IO_OP;
	
	cin >> n >> z;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	int l = 0, r = n / 2;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) l = m + 1;
		else r = m - 1;
	}
	cout << r << endl;
}