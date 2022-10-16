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
	
	string s;
	cin >> s;
	if(s.size() == 1) {
		cout << -1 << endl;
		return 0;
	}
	int ans = INF;
	for(int i=0;i<s.size();i++) {
		for(int j=0;j<s.size();j++) {
			if(j == i) continue;
			if(((s[j]-'0')*10 + s[i]-'0') % 25) continue;
			string t = s;
			int cnt = 0;
			for(int k=i;k<(int)s.size()-1;k++) {
				swap(t[k], t[k+1]);
				cnt++;
			}
			for(int k=(i > j ? j : j - 1);k<(int)s.size()-2;k++) {
				swap(t[k], t[k+1]);
				cnt++;
			}
			if(t[0] == '0') {
				int pos = -1;
				for(int k=0;k<(int)s.size() - 2;k++) {
					if(t[k] != '0') {
						pos = k;
						break;
					}
				}
				if(pos == -1) cnt = INF;
				else {
					for(int k=pos;k>0;k--){
						swap(t[k], t[k-1]);
						cnt++;
					}
				}
			}
			ans = min(ans, cnt);
		}
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;

}