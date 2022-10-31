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
        int sgn = 1, add = 0;
        for(int i = n-1; i>=0; i--){
            int cur = arr[add];
            if((n-1-i)%2 == 1) cur = 1-cur;;
            if(b[i] == cur){
                op.push_back(1);
            }
            op.push_back(i+1);
            add += sgn*i;
            sgn = -sgn;
        }
        cout << op.size() << " ";
        for(auto i : op) cout << i << " ";
        cout << endl;
    }
}