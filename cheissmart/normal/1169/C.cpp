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
int n, m, a[300005], b[300005];

bool ok(int k) {
	if(a[0] + k >= m) b[0] = 0;
	else b[0] = a[0];
	for(int i=1;i<n;i++) {
		int l = a[i], r = a[i] + k;
		if(r < m) {
			if(r < b[i-1]) return false;
			else{
				if(l >= b[i-1]) b[i] = l;
				else b[i] = b[i-1];
			}
		} else {
			r -= m;
			if(r >= b[i-1] || l <= b[i-1]) b[i] = b[i-1];
			else {
				b[i] = l;
			}
		}
	}
	for(int i=1;i<n;i++)
		if(b[i] < b[i-1])
			return false;
	return true;
}

int main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int l = 0, r = m-1;
	while(l <= r) {
		int mi = (l + r) / 2;
		if(ok(mi)) r = mi - 1;
		else l = mi + 1;
	}
	cout << l << endl;
}