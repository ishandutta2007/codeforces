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

tint ask(tint w) {
    cout << "? " << w << endl;
    cout.flush();

    tint r;
    cin >> r;
    return r;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T=1;
	forn(tc, T) {
        int n;
        cin >> n;
        tint bot = 0, top = 4000000 + n;
        while(top-bot>1) {
            tint mid = (top+bot)/2;
            tint r = ask(mid);
            if(r == 0 || r > 1) {
                bot = mid;
            } else {
                top = mid;
            }
        }

        tint best = top;
        forn(i, n+1) if(i > 1) {
            tint r = ask(top/i);
            if(r > 0) {
                best = min(r*(top/i), best);
            }
        }
        cout << "! " << best << endl;
        cout.flush();
    }
}