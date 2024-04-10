//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i,a,b) for (int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
int n, m;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    vi pos(n);
    rep(i, 0, n){
        cin >> pos[i];
    }

    sort(all(pos));
    set<int> s;
    rep(i, 0, n) {
        s.insert(pos[i] - m);
        s.insert(pos[i] + m);
    }
    ans = (int)s.size();
    for (int x: s) {
        int y = 0x3f3f3f3f;
        rep(i, 0, n) {
            y = min(y, abs(pos[i] - x));
        }
        if (y != m)
            ans--;
    }
    cout << ans<<endl;
    return 0;
}