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

bool ok[26];
int a[2000005];

signed main()
{
	IO_OP;
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	for(int i=0;i<k;i++) {
		char c;
		cin >> c;
		ok[c-'a'] = true;
	}
	int ans = 0, cur = 0;
	for(int i=0;i<n;i++) {
		if(ok[s[i]-'a'])
			cur++;
		else {
			ans += cur * (cur + 1) / 2;
			cur = 0;
		}
	}
	ans += cur * (cur + 1) / 2;
	cout << ans << endl;
	

}