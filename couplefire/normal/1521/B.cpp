#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n+2, 1);
        for(int i = 1; i<=n; i++) cin >> arr[i];
        vector<array<int, 4>> ans;
        for(int i = 1; i<=n-1; i++){
            int a = arr[i], b = arr[i+1];
            if(a <= b){
                while(__gcd(b, arr[i]) != 1 || __gcd(b, arr[i+2]) != 1) b++;
                ans.push_back({i, i+1, a, b});
                arr[i+1] = b;
            }
            else{
                while(__gcd(a, arr[i-1]) != 1 || __gcd(a, arr[i+1]) != 1) a++;
                ans.push_back({i, i+1, a, b});
                arr[i] = a;
            }
        }
        cout << ans.size() << endl;
        for(auto x : ans) cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
    }
}