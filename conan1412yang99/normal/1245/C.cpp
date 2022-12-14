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

const int M = 1e9 + 7;

int f[100005];

signed main()
{
	IO_OP;

	f[1] = 1, f[2] = 2;
	for(int i=3;i<100005;i++) f[i] = (f[i-1] + f[i-2]) % M;
	
	string s;
	cin >> s;
	vi v;
	for(int i=0;i<s.size();i++) {
		if(s[i] == 'm' || s[i] == 'w') {
			cout << 0 << endl;
			return 0;
		}
		if(s[i] != 'n' && s[i] != 'u') continue;
		int j = i;
		while(j < s.size() && s[j] == s[i]) j++;
		v.PB(j-i);
		i = j - 1;
	}
	int ans = 1;
	for(int e:v)
		ans = ans * f[e] % M;
	cout << ans << endl;
	
}