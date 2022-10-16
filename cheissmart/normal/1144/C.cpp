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

int vis[200005];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi a, b;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(vis[t] == 2) {
			cout << "NO" << endl;
			return 0;
		}
		if(vis[t]) b.PB(t);
		else a.PB(t);
		vis[t]++;
	}	
	cout << "YES" << endl;
	sort(ALL(a)), sort(ALL(b));
	reverse(ALL(b));
	cout << a.size() << endl;
	for(int e:a) cout << e << " ";
	cout << endl;
	cout << b.size() << endl;
	for(int e:b) cout << e << " ";
	cout << endl;
	
}