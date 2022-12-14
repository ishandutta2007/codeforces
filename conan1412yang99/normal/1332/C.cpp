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
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int ans = 0;
		V<string> v;
		for(int i=0;i<n;i+=k)
			v.PB(s.substr(i, k));
		for(int i=0;i<k/2;i++) {
			vi cnt(26);
			int cur = 0;
			for(int j=0;j<v.size();j++) {
				cnt[v[j][i]-'a']++;
				cnt[v[j][k-i-1]-'a']++;
				cur+=2;
			}
			cur -= *max_element(ALL(cnt));
			ans += cur;
		}
		if(k & 1) {
			vi cnt(26);
			int cur = 0;
			for(int j=0;j<v.size();j++) {
				cnt[v[j][k/2]-'a']++;
				cur++;
			}
			cur -= *max_element(ALL(cnt));
			ans += cur;
		}
		cout << ans << endl;
	}
	
}