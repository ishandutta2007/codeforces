#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
#define setio(x)
#else
#define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
#endif
const int MN = 1e5+3, BASE = 31, LOG = 20;
int cnt[131][131];
int main() {
	int n;
	scanf ("%d",&n);
	cnt[64][64] = n;
	while (1) {
		vector<pii> which;
		for (int i = 0; i <= 128; i++) {
			for (int j = 0; j <= 128; j++) {
				if (cnt[i][j] >= 4) {
					 which.push_back({i,j});
				}
			}
		}
		if (which.empty()) break;
		for (auto &au : which) {
			cnt[au.first][au.second] -= 4;
			cnt[au.first+1][au.second]++;
			cnt[au.first-1][au.second]++;
			cnt[au.first][au.second+1]++;
			cnt[au.first][au.second-1]++;
		}
	}
	int t;
	scanf ("%d",&t);
	while (t--) {
		int x,y; scanf ("%d %d",&x,&y);
		printf ("%d\n",x<-64||x>64||y<-64||y>64?0:cnt[x+64][y+64]);
	}
	return 0;
}