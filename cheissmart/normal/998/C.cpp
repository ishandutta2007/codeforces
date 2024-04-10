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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int x, y, n;
	string s;
	cin >> n >> x >> y >> s;		
	int cnt = 0;
	for(int i=0;i<s.size();) {
		if(s[i] == '1') {
			i++;
			continue;
		}
		while(i < s.size() && s[i] == '0') i++;
		cnt++;
	}	
	if(cnt == 0) {
		cout << 0 << endl;
		return 0;
	}
	int ans = cnt * y;
	ans = min(ans, (cnt - 1) * x + y);
	cout << ans << endl;
}