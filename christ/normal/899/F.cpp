#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
using bbst = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
set<int> pos[128];
char s[MN];
bbst inds;
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    scanf ("%s",s+1);
    for (int i = 1; i <= n; i++) inds.insert(i), pos[s[i]].insert(i);
    while (m--) {
        int l,r; char c;
        scanf ("%d %d %c",&l,&r,&c);
        int ll = *inds.find_by_order(l-1), rr = *inds.find_by_order(r-1);
        vector<int> rem;
        for (auto it = pos[c].lower_bound(ll); it != pos[c].end() && *it <= rr; ++it) {
            rem.push_back(*it);
            inds.erase(*it);
        }
        for (int i : rem) pos[c].erase(i);
    }
    for (int i : inds) printf ("%c",s[i]);
    printf ("\n");
    return 0;
}