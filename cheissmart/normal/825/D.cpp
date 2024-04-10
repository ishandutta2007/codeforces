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

int m[256], o[256], ans[256];

int main()
{
	IO_OP;
	
	string s, t;
	vi pos;
	cin >> s >> t;
	for(int i=0;i<s.size();i++) {
		char c = s[i];
		m[c]++;
		if(c == '?') pos.PB(i);
	}
	for(char c:t)
		o[c]++;
	
	while(true) {
		bool bk = 0;
		for(char c='a';c<='z';c++) {
			if(m[c] >= o[c])
				m[c] -= o[c];
			else {
				if(m[c] + m['?'] >= o[c]) {
					m['?'] -= o[c] - m[c];
					ans[c] += o[c] - m[c];
					ans['?'] -= o[c] - m[c];
					m[c] = 0;
				} else {
					bk = 1;
					break;
				}
			}
		}
		if(bk) break;
	}
	string r = s;
	for(char c='a';c<='z';c++) {
		for(int i=0;i<ans[c];i++) {
			r[pos.back()] = c;
			pos.pop_back(); 
		}
	}
	while(pos.size()) {
		r[pos.back()] = 'a';
		pos.pop_back();
	}
	cout << r << endl;
}