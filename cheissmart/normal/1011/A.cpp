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
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	sort(ALL(s));
	int j = 0, i, ans = 0;
	for(i=0;i<k&&j<n;i++) {
		ans += s[j] - 'a' + 1;
		char c = s[j];
		while(j < n && s[j]-c < 2) j++;
	}
	if(i == k) cout << ans << endl;
	else cout << -1 << endl;
	
}