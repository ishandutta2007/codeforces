// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
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

queue<int> leaves;
int father[200005];
int rtdist[200005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int nc = 1;
    rep(i, k) {
        ++nc;
        leaves.push(nc);
        father[nc] = 1;
        rtdist[nc] = 1;
    }
    while(nc != n) {
        int l = leaves.front(); leaves.pop();
        ++nc; leaves.push(nc); rtdist[nc] = rtdist[l]+1; father[nc] = l;
    }
    vector<int> v;
    while(!leaves.empty()) {
        v.pb(rtdist[leaves.front()]);
        leaves.pop();
    }
    sort(all(v));
    cout << v[v.size()-1] + v[v.size()-2] << endl;
    iter(i, 2, n+1)
        cout << father[i] << ' ' << i << endl;
}