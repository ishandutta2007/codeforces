#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	string s, t;
	cin >> s;
	vector<pi> v;
	for(int i=0;i<s.size();i++) {
		if(s[i] == '0' && v.size() && v.back().F == 1) {
			s[v.back().S] = '2';
			v.pop_back();
		}
		else {
			v.EB(s[i] - '0', i);
		}
	}
	for(char c:s)
		if(c == '2') cout << '1';
		else cout << '0';
}