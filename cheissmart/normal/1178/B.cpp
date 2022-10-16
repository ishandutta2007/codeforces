#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int pw[1000006], sw[1000006], o[1000006];

int32_t main()
{
	IO_OP;
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for(int i=2;i<=n;i++) {
		pw[i] = pw[i-1];
		if(s[i] == 'v' && s[i-1] == 'v')
			pw[i]++;
	}
	for(int i=n-1;i>=1;i--) {
		sw[i] = sw[i+1];
		if(s[i] == 'v' && s[i+1] == 'v')
			sw[i]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(s[i] == 'o') {
			ans += pw[i-1] * sw[i+1];
		}
	}
	cout << ans << endl;
}