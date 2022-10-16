#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;
	map<int, int> m;
	for(int i=1;i<44722;i++)
		m[i*i] = 1;
	int n, mx = -1;
	cin >> n;
	string s = to_string(n);
	for(int i=1;i<(1LL<<s.size());i++) {
		string t = "";
		for(int j=0;j<s.size();j++) {
			if(i & (1<<j)) {
				t += s[j];
			}
		}
		if(t[0] == '0') continue;
		if(m[stoi(t)]) {
			mx = max(mx, __builtin_popcount(i));
		}
	}
	if(mx == -1)
		cout << -1 << endl;
	else
		cout << (int)s.size() - mx << endl;
}