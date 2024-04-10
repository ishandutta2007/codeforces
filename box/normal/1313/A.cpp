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

int bit[9]; bool use[9];

int dfs(int a, int b, int c) {
    int best = 0;
    iter(i, 1, 8) {
        if(use[i]) continue;
        int na = a, nb = b, nc = c;
        if(i&1) na--;
        if(i&2) nb--;
        if(i&4) nc--;
        if(na != -1 && nb != -1 && nc != -1) {
            use[i] = 1;
            best = max(best, dfs(na, nb, nc)+1);
            use[i] = 0;
        }
    }
    return best;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << dfs(a, b, c) << endl;
    }
}