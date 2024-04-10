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

int p[15], p9[15];

int main()
{
	IO_OP;
	
	string s;
	cin >> s;
	s = ' ' + s;
	p9[0] = p[0] = 1;
	for(int i=1;i<11;i++)
		p9[i] = 9 * p9[i-1];
	for(int i=1;i<s.size();i++)
		p[i] = p[i-1] * (s[i] - '0');
	int ans = p[s.size()-1];
	for(int i=0;i<s.size();i++) {
		if(s[i+1] == '0') continue;
		int cans = p[i] * (s[i+1] - '0' - 1) * p9[s.size()-i-2];
		ans = max(cans, ans);
	}
	if(s.size() > 2)
		ans = max(ans, p9[s.size()-2]);
	cout << ans << endl;
}