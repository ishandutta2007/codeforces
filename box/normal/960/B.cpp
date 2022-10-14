// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

int a[1003], b[1003];

priority_queue<int, vector<int>> pq;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k1, k2; cin >> n >> k1 >> k2;
    k1 += k2;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        cin >> b[i];
        pq.push(abs(a[i]-b[i]));
    }
    while(k1--) {
        int t = pq.top(); pq.pop();
        if(t == 0) pq.push(1);
        else pq.push(t-1);
    }
    ll ans = 0;
    while(pq.size()) {
        ans = ans + 1ll * pq.top() * pq.top();
        pq.pop();
    }
    cout << ans << endl;
}