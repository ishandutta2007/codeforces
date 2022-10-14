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

queue<int> bq;
vector<int> elist[2005];
int dep[2005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    rep1(i, n) {
        int v; cin >> v;
        if(v == -1) elist[0].pb(i);
        else elist[v].pb(i);
    }
    int mxdep = 0; bq.push(0);
    while(!bq.empty()) {
        int a = bq.front(); bq.pop();
        for(const int& v:elist[a]) {
            mxdep = max(mxdep, dep[v] = dep[a]+1);
            bq.push(v);
        }
    }
    cout << mxdep << endl;
}