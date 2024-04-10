#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    int ocnt = 0, ecnt = 0;
    for(int i = 0; i<n; ++i){
        cin >> arr[i];
        if(arr[i]%2) ocnt++;
        else ecnt++;
    }
    if(ocnt==ecnt){
        vector<int> p1, p2, p3;
        for(int i = 0; i<n; ++i){
            if(i%2) p1.push_back(i);
            else p2.push_back(i);
            if(arr[i]%2) p3.push_back(i);
        }
        int a1 = 0, a2 = 0;
        for(int i = 0; i<n/2; ++i)
            a1 += abs(p1[i]-p3[i]), a2 += abs(p2[i]-p3[i]);
        cout << min(a1, a2) << '\n';
    } else if(abs(ocnt-ecnt)==1){
        int a = 0;
        vector<int> p1, p2;
        for(int i = 0; i<n; ++i){
            if(i%2==0) p1.push_back(i);
            if(ocnt>ecnt && arr[i]%2) p2.push_back(i);
            else if(ecnt>ocnt && arr[i]%2==0) p2.push_back(i);
        }
        for(int i = 0; i<p1.size(); ++i)
            a += abs(p1[i]-p2[i]);
        cout << a << '\n';
    } else{
        cout << -1 << '\n';
    }
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}