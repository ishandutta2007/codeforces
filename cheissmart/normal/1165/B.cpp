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

int a[200005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	int ans = 0, s = 0;
	for(int i=1;;i++) {
		int t = lower_bound(a+s, a+n, i) - a;
		if(t != n) {
			ans++;
			s = t + 1;
		} else
			break;
	}
	cout << ans << endl;
}