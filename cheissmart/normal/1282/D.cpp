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

int qry(string s) {
	int ret;
	cout << s << endl;
	cin >> ret;
	if(ret == 0) exit(0);
	return ret;
}

signed main()
{
	
	string s;
	for(int i=0;i<300;i++)
		s.PB('a');
	int a = 300 - qry(s);
	s.clear();
	for(int i=0;i<300;i++)
		s.PB('b');
	int b = 300 - qry(s);
	int len = a + b;
	string ans;
	for(int i=0;i<len;i++) {
		if(a == 0) {
			ans.PB('b');
			continue;
		} else if(b == 0) {
			ans.PB('a');
			continue;
		} else {
			string t=ans;
			t.PB('a');
			for(int j=0;j<b;j++)
				t.PB('b');
			if(qry(t) == a-1) {
				ans.PB('a');
				a--; 
			} else {
				ans.PB('b');
				b--;
			}
		}
	}
	qry(ans);
	
}