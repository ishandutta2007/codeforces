#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 1e5 + 87;

int a[N], c[N], pos[N];

int32_t main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		cin >> c[i];
	vector<pair<pi, int>> v;
	for(int i=1;i<=n;i++)
		v.PB({{c[i], a[i]}, i});
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++) {
		pos[v[i].S] = i;
	}
	int l = 0;
	while(m--) {
		int t, d;
		ll ans = 0, cans = 0;
		cin >> t >> d;
		cans += min(v[pos[t]].F.S, d) * v[pos[t]].F.F;
		int df = min(v[pos[t]].F.S, d);
		v[pos[t]].F.S -= df;
		d -= df;
		//cout << "- " << df << " " << t << endl;
		for(int i=l;i<v.size() && d > 0;i++) {
			int df = min(v[i].F.S, d);
			cans += df * v[i].F.F;
			v[i].F.S -= df;
			d -= df;
			if(v[i].F.S == 0)
				l = i + 1;
			//cout << "- " << df << " " << v[i].S << endl;
		}
		if(d == 0) ans = cans;
		cout << ans << endl;
	}
	
}