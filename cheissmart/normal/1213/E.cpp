#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	cout << "YES" << endl;
	if(s[0] == s[1] && t[0] == t[1]) {
		for(int i=0;i<n;i++)
			cout << "abc";
		return 0;
	}
	if(s == t) {
		for(int i=0;i<n;i++)
			cout << s[1] << s[0] << (char)('a'^'b'^'c'^s[0]^s[1]);
		return 0;
	}
	if(s[0] == t[1] && s[1] == t[0]) {
		for(int i=0;i<n;i++)
			cout << s[0];
		for(int i=0;i<n;i++)
			cout << (char)('a'^'b'^'c'^s[0]^s[1]);
		for(int i=0;i<n;i++)
			cout << s[1];
		return 0;
	}
	if(s[0] != s[1]) swap(s, t);
	if(s[0] == s[1]) {
		if(t[0] != s[0] && t[1] != s[0]) {
			for(int i=0;i<n;i++)
				cout << s[0] << t[1] << t[0];
			return 0;
		} else {
			for(int i=0;i<n;i++) {
				cout << t[0] << (char)('a'^'b'^'c'^t[0]^t[1]) << t[1];
			}
			return 0;
		}
	}
	if(s[0] == t[0]) {
		for(int i=0;i<n;i++)
			cout << s[1];
		for(int i=0;i<n;i++)
			cout << t[1];
		for(int i=0;i<n;i++)
			cout << s[0];
		return 0;
	}
	if(s[1] == t[1]) {
		for(int i=0;i<n;i++)
			cout << s[1];
		for(int i=0;i<n;i++)
			cout << s[0];
		for(int i=0;i<n;i++)
			cout << t[0];
		return 0;
	}
	if(s[1] == t[0]) swap(s, t);
	for(int i=0;i<n;i++)
		cout << s[0] << t[0] << s[1];

}