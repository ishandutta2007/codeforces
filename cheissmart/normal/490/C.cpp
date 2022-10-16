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

int ok[1000005];

int main()
{
	IO_OP;

	string s;
	int a, b;
	cin >> s >> a >> b;
	int p = 0, q = 0;
	for(int i=0;i<s.size()-1;i++) {
		p = p * 10 + s[i] - '0';
		p %= a;
		if(p == 0 && s[i+1] != '0') {
			ok[i]++;
		}
	}
	int pw = 1;
	for(int i=s.size()-1;i>0;i--) {
		q += pw * (s[i] - '0');
		pw *= 10;
		q %= b, pw %= b;
		if(q == 0 && s[i] != '0') {
			ok[i-1]++;
		}
	}
	for(int i=0;i<s.size();i++) {
		if(ok[i] == 2) {
			cout << "YES" << endl;
			cout << s.substr(0, i+1) << "\n" << s.substr(i+1) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}