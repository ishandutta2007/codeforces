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

int p[1000002], pw2[1000002];

int main()
{
	IO_OP;

	int n, q;
	string s;
	cin >> n >> q >> s;
	s = "?"+s;
	for(int i=1;i<=n;i++)
		p[i] += p[i-1] + s[i] - '0';
	pw2[0] = 1;
	for(int i=1;i<=n;i++)
		pw2[i] = pw2[i-1] * 2 % 1000000007;
	while(q--) {
		int l, r;
		cin >> l >> r;
		int a = p[r] - p[l-1], b = r-l+1-a;
		cout << 1LL * pw2[b] * (pw2[a]-1) % 1000000007 << endl;
	}
}