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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		string s( n, 'a');
		int l = 0, i;
		for(i=n-2;i>=0;i--) {
			l += n - i - 1;
			if(l >= k) break;
		}
		s[i] = 'b';
		k = l - k;
		s[i+k+1] = 'b';
		cout << s << endl;
	}	
	
}