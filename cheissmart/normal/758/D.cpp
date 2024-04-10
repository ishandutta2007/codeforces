#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

signed main()
{
	IO_OP;
	
	ll ans = 0, b = 1;
	int n;
	string k;
	cin >> n >> k;
	int j = k.size();
	while(j>0) {
		int c = 1, t = 0, i, m[65] = {0};
		m[j-1] = k[j-1]-'0';
		c *= 10;
		for(i=j-2;i>=0;i--) {
			m[i] = m[i+1] + (k[i]-'0')*c;
			m[i] = min(m[i], (ll)1e9+7);
			c = min(c, (ll)1e9+7);
			c *= 10;
		}
		bool flag = true;
		for(i=0;i<j;i++) {
			if(k[i] == '0') continue;
			if(m[i] < n) {
				flag = false;
				break;	
			}
		}
		if(flag)
			i = j-1;
		j = i;
		ans += m[j]*b;
		b *= n;
	}
	cout << ans << endl;
}