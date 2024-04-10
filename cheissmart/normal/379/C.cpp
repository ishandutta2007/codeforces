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

pi a[300002];
int ans[300002];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a, a+n);
	int mx = -1;
	for(int i=0;i<n;i++) {
		mx = max(mx+1, a[i].F);
		ans[a[i].S] = mx;
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
}