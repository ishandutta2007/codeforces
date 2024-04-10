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
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	if(k == 0) {
		cout << s << endl;
		return 0;
	}
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	} 
	if(s[0] != '1') k--;
	s[0] = '1';
	for(int i=1;i<n && k;i++)
		if(s[i] != '0'){
			s[i] = '0';
			k--;
		}
	cout << s << endl;
}