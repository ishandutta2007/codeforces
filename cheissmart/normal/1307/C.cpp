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

vi pos[26];

signed main()
{
	IO_OP;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
		pos[s[i]-'a'].PB(i);
	int ans = 0;
	for(int i=0;i<26;i++) ans = max(ans, (ll)pos[i].size());
	for(int i=0;i<26;i++) {
		for(int j=0;j<26;j++) {
			if(i == j) {
				ans = max(ans, (ll)((ll)pos[i].size() * (pos[i].size()-1) / 2));
			} else {
				int cur = 0;
				for(int ii=0, jj=0;ii<pos[i].size();ii++) {
					while(jj < pos[j].size() && pos[j][jj] < pos[i][ii]) jj++;
					cur += pos[j].size() - jj;
				}
				ans = max(ans, cur);
			}
		}
	}
	cout << ans << endl;
	
}