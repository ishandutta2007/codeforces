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

int nxt[26][100005];

int solve() {
	string s, t;
	cin >> s >> t;
	for(int i=0;i<=s.size();i++) {
		for(int j=0;j<26;j++) {
			nxt[j][i] = INF;
		}
	}
	for(int i=s.size()-1;i>=0;i--) {
		for(int j=0;j<26;j++) {
			nxt[j][i] = nxt[j][i+1];
		}
		nxt[s[i]-'a'][i] = i;
	}
	int pos = 0;
	int ans = 1;
	for(char c:t) {
		int cc = c-'a';
		if(nxt[cc][0] == INF) return -1;
		if(nxt[cc][pos] == INF) {
			pos = 0;
			ans++;
		}
		pos = nxt[cc][pos] + 1;
	}
	return ans;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		cout << solve() << endl;
	}

}