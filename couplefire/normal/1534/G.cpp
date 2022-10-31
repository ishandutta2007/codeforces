#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<array<int, 2>> arr;
    for(int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        arr.push_back({x+y, x-y});
    } 
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, less<>> lpq;
    priority_queue<int, vector<int>, greater<>> rpq;
    int ans = 0; lpq.push(0); rpq.push(0);
    for(auto [x, y] : arr){
        int l = lpq.top()-x, r = rpq.top()+x;
        if(l > y){
            lpq.push(y+x); lpq.push(y+x);
            lpq.pop(); rpq.push(l-x);
            ans += l-y;
        } else if(y > r){
            rpq.push(y-x); rpq.push(y-x);
            rpq.pop(); lpq.push(r+x);
            ans += y-r;
        } else lpq.push(y+x), rpq.push(y-x);
    }
    cout << ans/2 << endl;
}