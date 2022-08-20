/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,x,cost=2*MOD; 
vector<pair<pii,int>> vouch[200005];

void solve(int t) {
    sort(vouch[t].begin(),vouch[t].end());
    if (x-t > t) sort(vouch[x-t].begin(),vouch[x-t].end());
    int ind2 = vouch[x-t].size(), best = 2*MOD;
    F0Rd(i,vouch[t].size()) {
        while (ind2 > 0 && vouch[x-t][ind2-1].f.f > vouch[t][i].f.s) {
            ind2 --;
            best = min(best,vouch[x-t][ind2].s);
        }
        if (ind2 < vouch[x-t].size() && best != 2*MOD) 
            cost = min(cost,vouch[t][i].s+best);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x;
    F0R(i,n) {
        int l,r,cost; cin >> l >> r >> cost;
        vouch[r-l+1].pb({{l,r},cost});
    }
    FOR(i,1,x) solve(i);
    if (cost == 2*MOD) cout << -1;
    else cout << cost;
}