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
	
	V<string> in({"purple", "green", "blue", "orange", "red", "yellow"});
	V<string> out({"Power", "Time", "Space", "Soul", "Reality", "Mind"});
	int n;
	cin >> n;
	set<string> s;
	for(int i=0;i<n;i++) {
		string t;
		cin >> t;
		s.insert(t);
	}
	cout << 6 - n << endl;
	for(int i=0;i<6;i++) {
		if(!s.count(in[i])) {
			cout << out[i] << endl;
		}
	}

}