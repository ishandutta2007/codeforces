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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    T=1;
	forn(tc, T) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vi acc0(n), acc1(n);

        forn(i, n-1) {
            acc0[i+1] = acc0[i];
            acc1[i+1] = acc1[i];
            if(s[i] == s[i+1]) {
                if(s[i] == '0') {
                    acc0[i+1]++;
                } else {
                    acc1[i+1]++;
                }
            }
        }

        forn(i, q) {
            tint l, r;
            cin >> l >> r;
            r--; l--;
            tint ans = max(acc0[r]-acc0[l], acc1[r]-acc1[l])+1;
            cout << ans << endl;
        }
        cout << endl;
    }
}