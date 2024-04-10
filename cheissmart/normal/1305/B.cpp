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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	string s;
	cin >> s;
	int n = s.size();
	int mn = INF, pos = 0;
	for(int i=0;i<=n;i++) {
		int l = 0, r = 0;
		for(int j=0;j<i;j++) {
			if(s[j] == '(') l++;
		}
		for(int j=i;j<n;j++) {
			if(s[j] == ')') r++;
		}
		if(l == r) {
			if(l < mn) {
				mn = l;
				pos = i;
			}
		}
	}
	if(mn == 0) {
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;
		cout << mn*2 << endl;
		for(int j=0;j<pos;j++)
			if(s[j] == '(') cout << j + 1 << " ";
		for(int j=pos;j<n;j++)
			if(s[j] == ')') cout << j + 1 << " ";
		cout << endl;
	}
}