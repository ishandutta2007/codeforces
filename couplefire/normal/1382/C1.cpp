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
        int arr[n];
        string s1, s2; cin >> s1 >> s2;
        for(int i = 0; i<n; i++) arr[i] = s1[i]-'0';
        int b[n];
        for(int i = 0; i<n; i++) b[i] = s2[i]-'0';
        vector<int> op;
        for(int i = n-1; i>=0; i--){
            if(b[i] == arr[0]){
                op.push_back(1);
                arr[0] = 1-arr[0];
            }
            op.push_back(i+1);
            int temp[n];
            for(int j = 0; j<n; j++) temp[j] = arr[j];
            for(int j = 0; j<=i; j++){
                arr[j] = temp[i-j];
                arr[j] = 1-arr[j];
            }
        }
        cout << op.size() << " ";
        for(auto i : op) cout << i << " ";
        cout << endl;
    }
}