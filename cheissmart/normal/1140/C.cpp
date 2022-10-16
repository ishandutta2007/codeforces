#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

pi a[300005];

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	int ans = 0, s = 0;
	priority_queue<int, vi, greater<int>> pq;
	for(int i=0;i<n;i++)
		cin >> a[i].S >> a[i].F;
	sort(a, a+n);
	for(int i=n-1;i>=0;i--) {
		pq.push(a[i].S);
		s += a[i].S;
		if(pq.size() > k) {
			s -= pq.top();
			pq.pop();
		}
		ans = max(ans, a[i].F * s);
	}
	cout << ans << endl;
}