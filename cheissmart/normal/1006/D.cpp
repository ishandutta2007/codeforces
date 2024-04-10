#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;

	int n;
	string s, t;
	cin >> n >> s >> t;
	int ans = 0;
	for(int i=0;i<n/2;i++) {
		if(t[i] == t[n-i-1] && s[i] != s[n-i-1]) {
			ans++;
		}
		if(t[i] != t[n-i-1]) {
			auto a = s;
			if(s[i] == t[i] && a[n-i-1] == t[n-i-1]) continue;
			if(s[n-i-1] == t[i] && a[i] == t[n-i-1]) continue;
			if(s[i] == t[i] || a[n-i-1] == t[i] || a[i] == t[n-i-1] || a[n-i-1] == t[n-i-1]) ans++;
			else ans += 2;
		}
	}
	if((n&1) && s[n/2] != t[n/2]) ans++;
	cout << ans << endl;
}