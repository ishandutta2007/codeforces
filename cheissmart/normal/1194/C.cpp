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

int main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		string s, t, p, r;
		cin >> s >> t >> p;
		int i=0, j=0;
		for(j=0;j<t.size();j++) {
			if(i<s.size() && s[i] == t[j]) i++;
			else r += t[j];
		}
		if(i < s.size()) {
			cout << "NO" << endl;
			continue;
		}
		int m1[256] = {}, m2[256] = {};
		for(char c:p)
			m1[c]++;
		for(char c:r)
			m2[c]++;
		bool ok = 1;
		for(char c='a';c<='z';c++) {
			if(m1[c] < m2[c])
				ok = 0;
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}