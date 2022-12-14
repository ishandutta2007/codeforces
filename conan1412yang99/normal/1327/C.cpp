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

const int INF = 1e9 + 7, N = 203;

pi s[N], t[N];

signed main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<k;i++) cin >> s[i].F >> s[i].S;
	for(int i=0;i<k;i++) cin >> t[i].F >> t[i].S;
	string s;
	for(int i=0;i<n-1;i++) s += 'U';
	for(int i=0;i<m-1;i++) s += 'L';
	for(int i=0;i<n;i++) {
		if(i) s += 'D';
		if(i&1) {
			for(int j=0;j<m-1;j++)
				s += 'L';
		} else {
			for(int j=0;j<m-1;j++)
				s += 'R';
		}
	}
	cout << s.size() << endl;
	cout << s << endl;
}