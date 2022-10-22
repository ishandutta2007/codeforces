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

map<tint, tint> apps;
vi a;
bool lesser(const tint& b, const tint& c) {
    if(apps[a[b]] != apps[a[c]]) {
        return apps[a[b]] > apps[a[c]];
    }
    return a[b] < a[c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    cin >> T;
	forn(tc, T) {
        int n;
        cin >> n;
        a = vi(n);
        vvi pos(1);
        apps.clear();
        forn(i, n) {
            cin >> a[i];
            tint cur = apps[a[i]];
            apps[a[i]]++;
            if(pos.size() <= cur) pos.resize(cur+1);
            pos[cur].push_back(i);
        }
        vi ans(n);
        forn(i, pos.size()) {
            tint cur = pos[i].size();
            sort(pos[i].begin(), pos[i].end(), lesser);
            forn(j, cur) {
                ans[pos[i][j]] = a[pos[i][(j+1)%cur]];
            }
        }

        forn(i, n) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}