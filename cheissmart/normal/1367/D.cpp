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

const int INF = 1e9 + 7, N = 55;

int cnt[26], a[N], ans[N], m, cur;

void go() {
	vi v;
	for(int i = 0; i < m; i++) {
		if(ans[i] == -1 && a[i] == 0) {
			v.PB(i);
		}
	}
	if(v.empty()) return;
	while(cnt[cur] < v.size()) cur--;
	for(int i:v) ans[i] = cur;
	for(int i:v) {
		for(int j = 0; j < m; j++) {
			if(ans[j] == -1) {
				a[j] -= abs(i - j);
			}
		}
	}
	cur--;
	go();
}

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		memset(cnt, 0, sizeof cnt);
		memset(ans, -1, sizeof ans);
		cur = 25;
		string s;
		cin >> s;
		for(char c:s) cnt[c-'a']++;
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> a[i];
		}
		go();
		for(int i = 0; i < m; i++) cout << char('a' + ans[i]);
		cout << endl;
	}

}