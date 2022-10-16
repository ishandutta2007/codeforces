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

const int INF = 0x3f3f3f3f;

int nxt[26][100005], dp[255][255][255];
int n, q;
string s, x, y, z;

void upd(int i, int j, int k) {
	dp[i][j][k] = INF;
	if(i && dp[i-1][j][k] != INF) dp[i][j][k] = min(dp[i][j][k], nxt[x[i-1]-'a'][dp[i-1][j][k]]);
	if(j && dp[i][j-1][k] != INF) dp[i][j][k] = min(dp[i][j][k], nxt[y[j-1]-'a'][dp[i][j-1][k]]);
	if(k && dp[i][j][k-1] != INF) dp[i][j][k] = min(dp[i][j][k], nxt[z[k-1]-'a'][dp[i][j][k-1]]);
}

signed main()
{
	IO_OP;
	
	cin >> n >> q >> s;
	for(int i=0;i<26;i++) {
		int p = INF;		
		for(int j=n;j>=0;j--) {
			nxt[i][j] = p;
			if(j && s[j-1]-'a' == i) p = j;
		}
	}
	dp[0][0][0] = 0;
	while(q--) {
		char op;
		cin >> op;
		if(op == '+') {
			int t;
			char c;
			cin >> t >> c;
			if(t == 1) {
				x.PB(c);
				int i = x.size();
				for(int j=0;j<=y.size();j++)
					for(int k=0;k<=z.size();k++)
						upd(i, j, k);
			} else if(t == 2) {
				y.PB(c);
				int j = y.size();
				for(int i=0;i<=x.size();i++)
					for(int k=0;k<=z.size();k++)
						upd(i, j, k);
			} else {
				z.PB(c);
				int k = z.size();
				for(int i=0;i<=x.size();i++)
					for(int j=0;j<=y.size();j++)
						upd(i, j, k);
			}
		} else {
			int i;
			cin >> i;
			if(i == 1) x.pop_back();
			if(i == 2) y.pop_back();
			if(i == 3) z.pop_back();
		}
		if(dp[x.size()][y.size()][z.size()] != INF)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}