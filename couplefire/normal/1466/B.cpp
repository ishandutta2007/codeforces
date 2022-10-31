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
        vector<int> arr(n);
        for(int i = 0; i<n; i++) cin >> arr[i];
        set<int> st;
        for(int i = 0; i<n; i++){
            if(!st.count(arr[i])) st.insert(arr[i]);
            else st.insert(arr[i]+1);
        }
        cout << st.size() << endl;
    }
}