#include <bits/stdc++.h>
using namespace std;

void calc(int n, vector<int>& arr, vector<int>& ans){
    if(n==1) return;
    for(int i = 1; i<=n; ++i)
        if(arr[i]==n){
            ans.push_back(i);
            for(int a = 1, b = i; b>a; a++, b--)
                swap(arr[a], arr[b]);
            break;
        }
    for(int i = 1; i<=n; ++i)
        if(arr[i]==n-1){
            ans.push_back(i-1);
            for(int a = 1, b = i-1; b>a; a++, b--)
                swap(arr[a], arr[b]);
            break;
        }
    for(int i = 1; i<=n; ++i)
        if(arr[i]==n-1){
            ans.push_back(i+1);
            for(int a = 1, b = i+1; b>a; a++, b--)
                swap(arr[a], arr[b]);
            break;
        }
    for(int i = 1; i<=n; ++i)
        if(arr[i]==n){
            ans.push_back(i);
            for(int a = 1, b = i; b>a; a++, b--)
                swap(arr[a], arr[b]);
            break;
        }
    ans.push_back(n);
    for(int a = 1, b = n; b>a; a++, b--)
        swap(arr[a], arr[b]);
    calc(n-2, arr, ans);
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i = 1; i<=n; ++i)
        cin >> arr[i];
    for(int i = 1; i<=n; ++i)
        if(arr[i]%2 != i%2){
            cout << -1 << '\n';
            return;
        }
    vector<int> ans;
    calc(n, arr, ans);
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}