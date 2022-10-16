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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;


signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int pos[102], a[102];
		bool vis[102];
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		int j = 1;
		memset(vis, 0, sizeof vis);
		for(int i=1;i<=n;i++) {
			if(vis[i]) continue;
			vis[i] = 1;
			cout << i << " ";
			if(pos[i] != 1) {
				swap(a[pos[i]], a[pos[i]-1]);
				pos[a[pos[i]-1]]++, pos[i]--;
			}
			for(;j<pos[i];j++) {
				if(vis[a[j]] == 0)
				cout << a[j] << " ";
				vis[a[j]] = 1;
			}
		}
		cout << endl;
	}	
	
}