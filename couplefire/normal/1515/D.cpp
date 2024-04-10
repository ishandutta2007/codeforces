#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    multiset<int> rcolors;
    multiset<int> lcolors;
    for(int i = 0; i<l; i++){
        int c; cin >> c;
        lcolors.insert(c);
    }
    for(int i = 0; i<r; i++){
        int c; cin >> c;
        rcolors.insert(c);
    }
    if(l > r){
        swap(l, r);
        swap(lcolors, rcolors);
    }
    vector<int> badleft;
    for(auto x : lcolors){
        auto it = rcolors.find(x);
        if(it == rcolors.end()){
            badleft.push_back(x);
            continue;
        }
        rcolors.erase(it);
    }
    map<int, int> rtmp;
    priority_queue<int> pq;
    for(auto x : rcolors) rtmp[x]++;
    for(auto x : rtmp) pq.push(x.second%2);
    int ans = 0; ans += badleft.size();
    ans += (r-l)/2;
    for(auto x : badleft){
        int y = pq.top(); pq.pop();
        pq.push((y+1)%2);
    }
    int cntodd = 0;
    while(!pq.empty() && pq.top() == 1) cntodd++, pq.pop();
    ans += cntodd/2;
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}