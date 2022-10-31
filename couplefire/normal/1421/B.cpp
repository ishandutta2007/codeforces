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
        char grid[n][n];
        for(int i = 0; i<n; i++){
            string s; cin >> s;
            for(int j = 0; j<n; j++) grid[i][j] = s[j];
        }
        int val1 = grid[0][1]-'0', val2 = grid[1][0] - '0', val3 = grid[n-2][n-1]-'0', val4 = grid[n-1][n-2]-'0';
        if(val1 != val2 && val3 != val4){
            cout << 2 << endl;
            if(val1 == 0) cout << 1 << " " << 2 << endl;
            else cout << 2 << " " << 1 << endl;
            if(val3 == 1) cout << n-1 << " " << n << endl;
            else cout << n << " " << n-1 << endl;
        }
        else if(val1 == val2 && val3 == val4){
            if(val1 != val3){
                cout << 0 << endl;
            }
            else{
                cout << 2 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 2 << " " << 1 << endl;
            }
        }
        else if(val1 == val2){
            cout << 1 << endl;
            if(val3 == val1){
                cout << n-1 << " " << n << endl;
            }
            else{
                cout << n << " " << n-1 << endl;
            }
        }
        else{
            cout << 1 << endl;
            if(val1 == val3){
                cout << 1 << " " << 2 << endl;
            }
            else{
                cout << 2 << " " << 1 << endl;
            }
        }
    }
}