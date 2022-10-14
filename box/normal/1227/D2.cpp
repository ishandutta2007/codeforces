// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

vector<int> aray;
vector<int> spco;
vector<int> indexes[200005];
vector<pii> query[200005];
int answer[200005];

map<int, int> sparse, desparse;

ordered_set<int> best;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    rep(i, n) {
        int v; cin >> v;
        aray.pb(v);
        spco.pb(v);
    }
    sort(all(spco));
    int id = 0;
    for(int& v : spco) {
        if(!sparse.count(v)) {
            sparse[v] = id;
            desparse[id] = v;
            id++;
        }
    }
    rep(i, n) indexes[sparse[aray[i]]].pb(i);
    int m; cin >> m;
    rep(i, m) {
        int k, ind; cin >> k >> ind;
        query[k].pb({ind, i});
    }
    for(int pushin=id-1; pushin>=0; pushin--) {
        sort(all(indexes[pushin]));
        for(int& index:indexes[pushin]) {
            best.insert(index);
            for(const pii& v:query[best.size()])
                answer[v.se] = aray[*best.find_by_order(v.fi-1)];
        }
    }
    rep(i, m) cout << answer[i] << endl;
}