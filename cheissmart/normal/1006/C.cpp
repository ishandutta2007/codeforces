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

const int N = 2e5 + 87;

ll a[N], pre[N], suf[N];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	pre[0] = a[0], suf[n-1] = a[n-1];
	for(int i=1;i<n;i++) {
		pre[i] = pre[i-1] + a[i];
		suf[n-i-1] = suf[n-i] + a[n-i-1];
	}
	ll ans = 0;
	for(int i=0, j=n-1;i<j;) {
		if(pre[i] == suf[j]) {
			ans = pre[i];
			i++,j--;
		} else if(pre[i] > suf[j]) {
			j--;
		} else {
			i++;
		}
	}
	cout << ans << endl;
}