#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[200005];

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int h, n, ans = 0;
		cin >> h >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		int pos = h;
		for(int i=1;i<n;i++) {	
			int nxt = a[i];
			pos = nxt + 1;
			if(pos <= 2) break;
			if(i == n-1) {
				ans++;
				break;
			}
			if(a[i+1] == nxt - 1) {
				pos = nxt - 1;
				i++;
			} else {
				ans++;
				pos = nxt - 1;
			}
		}
		cout << ans << endl;
	}
	
}