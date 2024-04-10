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

int fact[20], ans = 0;
int take[10], cnt[10];

void go(int c) {
	if(c == 10) {
		int n = 0;
		for(int i=0;i<10;i++) n += take[i];
		int add = fact[n], de = 0;
		for(int i=0;i<10;i++) add /= fact[take[i]];
		if(take[0]) {
			de = fact[n - 1];
			for(int i=1;i<10;i++) de /= fact[take[i]];
			de /= fact[take[0] - 1];
		}
		ans += add - de;
		return;
	}
	if(cnt[c] == 0) go(c+1);
	for(int i=1;i<=cnt[c];i++) {
		take[c] = i;
		go(c+1);
	}
}

signed main()
{
	IO_OP;
	fact[0] = 1;
	for(int i=1;i<20;i++)
		fact[i] = i * fact[i - 1];
	string s;
	cin >> s;
	for(char c:s)
		cnt[c-'0']++;
	go(0);
	cout << ans << endl;
	
}