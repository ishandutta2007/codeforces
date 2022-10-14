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

bool inaloop[200005];

int cost[200005];
int indeg[200005], nex[200005];
int n;

queue<int> bq;

void topsort() {
    rep1(i, n) indeg[nex[i]]++;
    rep1(i, n) {
        if(!indeg[i]) bq.push(i);
    }
    while(!bq.empty()) {
        int t = bq.front(); bq.pop();
        indeg[nex[t]]--;
        if(!indeg[nex[t]]) bq.push(nex[t]);
    }
    rep1(i, n) if(indeg[i]) inaloop[i] = true;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep1(i, n) cin >> cost[i];
    rep1(i, n) cin >> nex[i];
    topsort();
    int ans = 0;
    rep1(i, n) {
        if(!inaloop[i]) continue;
        int subans = cost[i];
        int t = i;
        while(inaloop[t]) {
            subans = min(subans, cost[t]);
            inaloop[t] = false;
            t = nex[t];
        }
        ans += subans;
    }
    cout << ans << endl;
}