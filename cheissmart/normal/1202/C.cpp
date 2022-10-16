#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

string d = "WASD";
int dd[][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
pair<pi, pi> v[200005], u[200005];
pi r[200005];

int a(pair<pi, pi> p) {
	return (p.F.F - p.F.S + 1) * (p.S.F - p.S.S + 1);
}

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		{
			int x = 0, y = 0, mxx = 0, mnx = 0, mxy = 0, mny = 0;
			for(int i=0;i<s.size();i++) {
				int jj = d.find(s[i]);
				x += dd[jj][0], y += dd[jj][1];
				mxx = max(mxx, x);
				mnx = min(mnx, x);
				mxy = max(mxy, y);
				mny = min(mny, y);
				v[i] = {{mxx, mnx}, {mxy, mny}};
				r[i] = {x, y};
			}
		}
		{
			int x = r[s.size()-1].F, y = r[s.size()-1].S, mxx = x, mnx = x, mxy = y, mny = y;
			for(int i=s.size()-1;i>=1;i--) {
				int jj = d.find(s[i]);
				x -= dd[jj][0], y -= dd[jj][1];
				mxx = max(mxx, x);
				mnx = min(mnx, x);
				mxy = max(mxy, y);
				mny = min(mny, y);
				u[i] = {{mxx-r[i-1].F, mnx-r[i-1].F}, {mxy-r[i-1].S, mny-r[i-1].S}};
			}
		}
		int ans = a(v[s.size()-1]);
		for(int i=0;i<s.size()-1;i++) {
			int gmxx = v[i].F.F, gmnx = v[i].F.S, gmxy = v[i].S.F, gmny = v[i].S.S;
			for(int j=0;j<4;j++) {
				pi rr = {r[i].F + dd[j][0], r[i].S + dd[j][1]};
				int nmxx = rr.F + u[i+1].F.F,
					nmnx = rr.F + u[i+1].F.S,
					nmxy = rr.S + u[i+1].S.F,
					nmny = rr.S + u[i+1].S.S;
				int mxx = max(gmxx, nmxx);
				int mnx = min(gmnx, nmnx);
				int mxy = max(gmxy, nmxy);
				int mny = min(gmny, nmny);
				ans = min(ans, a({{mxx, mnx}, {mxy, mny}}));
			}
 		}
		cout << ans << endl;
	}

	
}