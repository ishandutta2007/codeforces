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

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi vis(n+1);
		int no = -1;
		for(int i=0;i<n;i++) {
			int k;
			cin >> k;
			int go = -1;
			for(int j=0;j<k;j++) {
				int t;
				cin >> t;
				if(go == -1 && !vis[t]) {
					go = t;
				}
			}
			if(go != -1) {
				vis[go] = 1;
			} else {
				no = i + 1;
			}
		}
		if(no == -1) cout << "OPTIMAL" << endl;
		else{
			cout << "IMPROVE" << endl;
			int go;
			for(int i=1;i<=n;i++) if(!vis[i]) go = i;
			cout << no << " " << go << endl;
		}
	}	
	
}