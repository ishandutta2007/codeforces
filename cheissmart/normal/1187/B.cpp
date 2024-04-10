#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int p[26][200005], ct[26];

bool ok(int m) {
	for(int i=0;i<26;i++)
		if(p[i][m] < ct[i])
			return false;
	
	return true;
}

int main()
{
	IO_OP;
	
	int n, m;
	string s;
	cin >> n >> s >> m;
	s = " " + s;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<26;j++)
			p[j][i] = p[j][i-1] + (s[i] - 'a' == j);
	}
	while(m--) {
		string t;
		cin >> t;
		memset(ct, 0, sizeof ct);
		for(char c:t)
			ct[c-'a']++;
		int l = 1, r = n;
		while(l <= r) {
			int m = (l + r) / 2;
			if(ok(m)) r = m - 1;
			else l = m + 1;
		}
		cout << l << endl;
	}
	
}