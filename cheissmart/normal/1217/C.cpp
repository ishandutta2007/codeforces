#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int lst[200005];

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int l = -1;
		for(int i=0;i<s.size();i++) {
			lst[i] = l;
			if(s[i] == '1')
				l = i;
		}
		int ans = 0;
		for(int i=0;i<s.size();i++) {
			int sm = 0;
			for(int j=i;j>=0 && sm <= s.size();) {
				if(i - j >= 20) break;
				sm += (ll)(s[j] - '0') << (i - j);
				if(i-lst[j] >= sm && sm >= i - j + 1) ans++;
				j = lst[j];
			}
		}
		cout << ans << endl;
	}


}