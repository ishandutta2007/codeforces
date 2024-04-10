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
        string b; cin >> b;
        vector<int> res;
        for(int i = 0; i<n; i++){
            if(!res.empty() && res.back() == b[i]-'0'+1){
                res.push_back(b[i]-'0');
            }
            else{
                res.push_back(b[i]-'0'+1);
                // cout << b[i]-'0'+1 << " " << res.back() << endl;
            }
            cout << res.back()-b[i]+'0';
        }
        // for(int i = 0; i<n; i++) cout << res.back();
        cout << endl;
    }
}