#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	int T=1;
	
	forn(tc, T) {
		tint n;
		cin >> n;
		vvi arr(n), ans(n);
		map<tint, set<pair<tint, tint>>> nums;
		vector<set<tint>> rem(n);
		forn(i, n) {
			tint m;
			cin >> m;
			arr[i] = vi(m);
			ans[i] = vi(m, -1);
			forn(j, m) {
				cin >> arr[i][j];
				nums[arr[i][j]].insert({i, j});
				rem[i].insert(j);
			}
		}
		int anda = 1;
		for(auto& p: nums) {
			if(p.second.size() % 2) anda = 0;
		}
		if(!anda) {
			cout << "NO" << endl;
			continue;
		}
		
		forn(i, n) forn(j, arr[i].size()) if(ans[i][j] == -1) {
			ans[i][j] = 0;
			rem[i].erase(j);
			nums[arr[i][j]].erase({i, j});
			auto next = *nums[arr[i][j]].begin();
			ans[next.first][next.second] = 1;
			rem[next.first].erase(next.second);
			nums[arr[i][j]].erase(nums[arr[i][j]].begin());
			while(next.first != i) {
				auto nj = *rem[next.first].begin();
				ans[next.first][nj] = 0;
				rem[next.first].erase(nj);
				tint act = arr[next.first][nj];
				nums[act].erase({next.first, nj});
				next = *nums[act].begin();
				ans[next.first][next.second] = 1;
				rem[next.first].erase(next.second);
				nums[act].erase(nums[act].begin());
			}
		}
		
		cout << "YES" << endl;
		forn(i, n) {
			forn(j, arr[i].size()) {
				if(ans[i][j]) cout << "R"; else cout << "L";
			}
			cout << endl;
		}
	}
}