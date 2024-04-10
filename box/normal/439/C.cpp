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

vector<int> cou[100005];
int p;

vector<int> even;
queue<int> odd;

priority_queue<pii> pq;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k >> p;
    rep(i, n) {
        int v; cin >> v;
        if(v % 2) odd.push(v);
        else even.pb(v);
    }
    if(p) rep(i, even.size()) cou[i % p].pb(even[i]);
    rep(i, k-p) {
    if(odd.empty()) {
        cout << "NO" << endl;
        return 0;
    }
        cou[p+i].pb(odd.front());
        odd.pop();
    }
    if(odd.size() % 2) {
        cout << "NO" << endl;
        return 0;
    }
    rep(i, k) pq.push({-cou[i].size(), i});
    while(odd.size()) {
        pii v = pq.top(); pq.pop();
        cou[v.se].pb(odd.front());
        odd.pop();
        cou[v.se].pb(odd.front());
        odd.pop();
        pq.push({-cou[v.se].size(), v.se});
    }
    rep(i, k) if(!cou[i].size()) {
        cout << "NO" << endl;
        return 0;
    }
    if(!p) rep(i, even.size()) cou[i % k].pb(even[i]);
    cout << "YES" << endl;
    rep(i, k) {
        cout << cou[i].size();
        for(int& v:cou[i]) cout << ' ' << v;
        cout << endl;
    }
}