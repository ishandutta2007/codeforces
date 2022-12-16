#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 200200;
vector<int> at[NMAX];

ll p[NMAX], b[NMAX];
ll pi[NMAX];
int n, k;

bool check(ll m) {
    for(int i=0;i<=k;++i) {
        at[i] = vector<int>();
    }
    for(int i=0;i<n;++i) {
        p[i] = pi[i];
        ll v = p[i]/b[i];
        if(v < k) at[v].push_back(i);
    }
    int j = 0;
    for(int i=0;i<k && j <= k;++i) {
        //cerr << " " << i << " " << j << endl;
        while(at[j].size() == 0 && j <= k) ++j;
        if(j > k) return true;
        if(j < i) return false;
        //cerr << " - " << endl;
        int u = at[j].back(); at[j].pop_back();
        //cerr << " -- " << p[u] << " " << b[u] << " u " << u << endl;
        p[u] += m;
        ll v = p[u]/b[u];
        ////cerr << " at " << v << " push back " << u << " " << p[u] << " " << b[u] << endl;
        if(v < k) at[v].push_back(u);
        //cerr << "  -" << endl;
    }
    while(at[j].size() == 0 && j <= k) ++ j;
    //if(j < k) return false;
    return true;
}

ll bs() {
    const ll TOP = 2000000000001LL;
    ll lo = 0, hi = TOP;
    while(lo < hi) {
        ll m =(lo+hi)/2;
        if(check(m)) {
            hi = m;
        } else {
            lo = m+1;
        }
    }
    return (lo == TOP ? -1 : lo);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;++i) {
        cin >> pi[i];
    }
    for(int i=0;i<n;++i) {
        cin >> b[i];
    }
    cout << bs() << endl;
    return 0;
}