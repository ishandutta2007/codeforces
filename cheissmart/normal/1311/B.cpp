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

int a[102], ok[102], b[102];

bool solve() {
	memset(ok, 0, sizeof ok);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		ok[t] = 1;
	}
	for(int i=1;i<=n;i++) {
		int j = i;
		for(int k=i;k<=n;k++) {
			if(a[k] < a[j]) j = k;
		}
		for(int k=i;k<=j-1;k++) {
			if(!ok[k]) return false;
		}
		for(int k=j-1;k>=i;k--) swap(a[k], a[k+1]);
	}

	return true;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		cout << (solve() ? "YES" : "NO") << endl;
	}	
	
}