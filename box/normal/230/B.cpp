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
#define int ll
const int MOD = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while(q--) {
        ll v; cin >> v;
        if(v == 1) { cout << "NO" << endl; continue; }
        ll sqr = 0, l = (ll)(sqrt((double)(v))-10), r = (ll)(sqrt((double)(v))+10);
        while(l <= r) {
            ll m = (l+r)>>1;
            if(m*m <= v) { sqr = m; l = m+1; }
            else r = m-1;
        }
        if(sqr*sqr != v) { cout << "NO" << endl; continue; }
        bool pr = true;
        for(int p=2; p*p<=sqr && pr; p++)
            if(sqr%p == 0) pr = false;
        if(pr) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}