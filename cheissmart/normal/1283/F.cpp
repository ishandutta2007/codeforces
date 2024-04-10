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

int a[200005];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	set<int> s;
	V<pi> ans;
	for(int i=1;i<=n;i++)
		s.insert(i);
	for(int i=0;i<n-1;i++)
		cin >> a[i];
	int k = a[0];
	s.erase(k);
	for(int i=0;i<n-1;) {
		int mx = *s.rbegin();
		int lst = a[i];
		if(s.count(a[i])) s.erase(a[i]);
		i++;
		while(i < n-1 && s.count(a[i]) && a[i] != mx) {
			ans.EB(lst, a[i]);
			lst = a[i];
			s.erase(a[i]);
			i++;
		}
		ans.EB(lst, mx);
		s.erase(mx);
	}
	cout << k << endl;
	for(pi p:ans) cout << p.F << " " << p.S << endl;
	
}