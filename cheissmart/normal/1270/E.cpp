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

V<pair<pi, int>> s[2][2];

void split(V<pair<pi, int>>& v) {
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			s[i][j].clear();
	for(auto p:v)
		s[p.F.F&1][p.F.S&1].PB(p);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	V<pair<pi, int>> v;
	for(int i=1;i<=n;i++) {
		int x, y;
		cin >> x >> y;
		v.EB(MP(x, y), i);
	}	
	while(true) {
		split(v);
		V<pi> have;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
			if(s[i][j].size()) have.EB(i, j);
		if(have.size() == 1) {
			int i = have[0].F, j = have[0].S;
			v = s[i][j];
			for(auto& p:v) p.F.F -= i, p.F.S -= j, p.F.F /= 2, p.F.S /= 2;
		} else {
			if(have.size() == 2){
				int i = have[0].F, j = have[0].S;
				cout << s[i][j].size() << endl;
				for(auto p:s[i][j]) cout << p.S << " ";
			} else {
				cout << s[0][0].size()+s[1][1].size() << endl;
				for(auto p:s[0][0]) cout << p.S << " ";
				for(auto p:s[1][1]) cout << p.S << " ";
			}
			break;
		}
	}
}