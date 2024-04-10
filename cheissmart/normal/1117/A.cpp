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

int a[100005];

int main()
{
	IO_OP;
	
	int n, mx = -INF;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		mx = max(mx, a[i]);	
	}
	int ans = 0, cnt = 0;
	for(int i=0;i<n;i++) {
		if(a[i] == mx) {
			cnt++;
		} else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cout << ans << endl;
}