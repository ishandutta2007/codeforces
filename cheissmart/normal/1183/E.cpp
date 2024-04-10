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

map<string, bool> vis;

int32_t main()
{
	IO_OP;

	int n, k, ans = 0;
	string s;
	cin >> n >> k >> s;	
	V<string> v({s});
	for(int i=0;i<(int)v.size()&&(int)v.size()<k;i++) {
		string t = v[i];
		for(int j=0;j<(int)t.size();j++) {
			string r;
			if(j) r += t.substr(0, j);
			if(j + 1 < (int)t.size()) r += t.substr(j+1);
			if(!vis[r]) {
				vis[r] = true;
				v.PB(r);
				ans += n - r.size();
			}
			if((int)v.size() == k) break;
		}

	}
	if((int)v.size() < k) ans = -1;
	cout << ans << endl;
}