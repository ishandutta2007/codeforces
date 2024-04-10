#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long
//#define double long double
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.first != b.first) return (a.first > b.first);
    return (a.second < b.second);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i=0; i < n; i++){
        int s = 0;
        for (int j=0; j < 4; j++){
            int x;
            cin >> x;
            s += x;
        }
        v.push_back(make_pair(s, i));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i=0;i<n;i++) if (v[i].second == 0){
        cout << i+1;
    }
    return 0;
}