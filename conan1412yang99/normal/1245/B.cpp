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
	
	int t;
	cin >> t;
	while(t--) {
		int n, a,b,c;
		vi aa, bb, cc;
		string s;
		cin >> n >> a >> b >> c >> s;
		for(int i=0;i<n;i++) {
			if(s[i] == 'S') aa.PB(i);
			else if(s[i] == 'R') bb.PB(i);
			else cc.PB(i);
		}
		int w = min((int)aa.size(), a) + min((int)bb.size(), b) + min((int)cc.size(), c);
		if(w >= (n+1)/2) {
			cout << "YES" << endl;
			string t(n, ' ');
			vi o;
			for(int i=0;i<min(a, (int)aa.size());i++) t[aa[i]] = 'R';
			for(int i=0;i<min(b, (int)bb.size());i++) t[bb[i]] = 'P';
			for(int i=0;i<min(c, (int)cc.size());i++) t[cc[i]] = 'S';
			a -= min(a, (int)aa.size());
			b -= min(b, (int)bb.size());
			c -= min(c, (int)cc.size());
			for(int i=0;i<n;i++) {
				if(t[i] == ' ') {
					if(a) t[i] = 'R', a--;
					else if (b) t[i] = 'P', b--;
					else t[i] = 'S', c--;
				}
			}
			cout << t << endl;
		}
		else cout << "NO" << endl;
	}	
	
}