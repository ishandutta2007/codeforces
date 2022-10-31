#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    vector<int> orig = arr;
    vector<int> res;
    int cur = 0;
    for(int i = 0; i<n; ++i){
        // 110
        if(i>=2 && arr[i-2]==1 && arr[i-1]==1 && arr[i]==0){
            if(cur%2==1) continue;
            int j = i;
            while(j>=2 && arr[j-2]==1 && arr[j-1]==1 && arr[j]==0)
                res.push_back(j), arr[j-2] = arr[j-1] = 0, j -= 2;
            cur = 0;
            continue;
        }
        // 100
        if(i>=2 && arr[i-2]==1 && arr[i-1]==0 && arr[i]==0){
            arr[i-1] = arr[i] = 1; cur += 2;
            res.push_back(i);
            continue;
        }
        // 101
        if(i>=2 && arr[i-2]==1 && arr[i-1]==0 && arr[i]==1){
            assert(cur%2==1);
            res.push_back(i);
            arr[i-2] = arr[i] = 0;
            int j = i-2;
            while(j>=2 && arr[j-2]==1 && arr[j-1]==1 && arr[j]==0)
                res.push_back(j), arr[j-2] = arr[j-1] = 0, j -= 2;
            cur = 0;
            continue;
        }
        // 011
        if(i>=2 && arr[i-2]==0 && arr[i-1]==1 && arr[i]==1){
            res.push_back(i); arr[i-1] = arr[i] = 0;
            cur = 0;
            continue;
        }
        // 000, 001, 010, 111
        if(arr[i]) ++cur;
    }
    int lo = n+1;
    for(int i = 0; i<n; ++i)
        if(arr[i]) lo = min(lo, i);
    if(lo<n && lo>0){
        for(int i = lo-1; i<n-2; i+=2){
            int tmp = (arr[i]^arr[i+1]^arr[i+2]);
            arr[i] = arr[i+1] = arr[i+2] = tmp;
            res.push_back(i+2);
        }
    }
    for(int i = 0; i<n; ++i)
        if(arr[i]){
            cout << "NO" << '\n';
            return;
        }
    cout << "YES" << '\n';
    assert((int)res.size()<=n);
    cout << res.size() << '\n';
    for(auto x : res)
        cout << x-1 << ' ';
    cout << '\n';
    for(auto x : res){
        int tmp = (orig[x]^orig[x-1]^orig[x-2]);
        orig[x] = orig[x-1] = orig[x-2] = tmp;
    }
    for(int i = 0; i<n; ++i)
        assert(orig[i]==0);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}