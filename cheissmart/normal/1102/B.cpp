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

int a[5555], ct[5555], clr[5555], ans[5555];

int main()
{
	IO_OP;

	int n, k;
	cin >>n >> k;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		ct[a[i]]++;
	}
	int mx = -1;
	for(int i=0;i<5555;i++)
		mx = max(mx, ct[i]);
	if(k > n || mx > k) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<pi> v;
	for(int i=0;i<n;i++)
		v.PB(MP(a[i], i));
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++)
		ans[v[i].S] = i % k + 1;
	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
}