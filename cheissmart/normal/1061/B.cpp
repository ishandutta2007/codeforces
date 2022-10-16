#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[100005];

int main()
{
	IO_OP;
	
	int n, m;
	ll tot = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		tot += a[i];
	}
	sort(a, a+n);
	ll re = 0, h = 0;
	for(int i=0;i<n;i++) {
		if(h < a[i]) {
			h++;
		}
		if(i == n-1) {
			re += a[i] - h;
		}
		re++;
	}
	cout << tot - re << endl;
}