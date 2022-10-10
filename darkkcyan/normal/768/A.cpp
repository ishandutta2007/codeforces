#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()

int n;
multiset<int> a;

int main() {
#ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    
    for (int i = n; i--; ) {
        int t; cin >> t;
        a.insert(t);
    }

    a.erase(*a.begin());
    if (sz(a)) a.erase(*(--a.end()));
    cout << sz(a);

    return 0;
}