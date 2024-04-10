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

int cnt[26];

signed main()
{
	IO_OP;

	int k, n;
	string s;
	cin >> n >> k >> s;	
	for(int i=0;i<n;) {
		int j = i;
		while(i < n && s[j] == s[i]) i++;
		cnt[s[j]-'a'] += (i - j) / k;
	}
	int mx = 0;
	for(int i=0;i<26;i++) mx = max(mx, cnt[i]);
	cout << mx << endl;
}