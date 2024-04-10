#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int r, c; cin >> r >> c;
        char grid[r][c];
        int cnt = 0;
        for(int i = 0; i<r; i++){
            string s; cin >> s;
            for(int j = 0; j<c; j++){
                grid[i][j] = s[j];
                cnt += (s[j] == 'P');
            }
        }
        if(cnt == 0){
            cout << 0 << endl;
            continue;
        }
        if(cnt == r*c){
            cout << "MORTAL" << endl;
            continue;
        }
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for(int i = 0; i<c; i++){
            c1 += grid[0][i]=='A';
            c3 += grid[r-1][i] == 'A';
        }
        for(int i = 0; i<r; i++){
            c2 += grid[i][c-1]=='A';
            c4 += grid[i][0] == 'A';
        }
        if(c1 == c || c2 == r || c3 == c || c4 == r){
            cout << 1 << endl;
            continue;
        }
        if(grid[0][0] == 'A' || grid[0][c-1] == 'A' || grid[r-1][0] == 'A' || grid[r-1][c-1] == 'A'){
            cout << 2 << endl;
            continue;
        }
        bool row = false, col = false;
        for(int i = 0; i<r; i++){
            int cc = 0;
            for(int j = 0; j<c; j++) cc += grid[i][j] == 'A';
            row |= (cc==c);
        }
        for(int i = 0; i<c; i++){
            int rr = 0;
            for(int j = 0; j<r; j++) rr += grid[j][i] == 'A';
            col |= (rr==r);
        }
        if(row || col){
            cout << 2 << endl;
            continue;
        }
        if(c1 > 0 || c2 > 0 || c3 > 0 || c4 > 0){
            cout << 3 << endl;
            continue;
        }
        cout << 4 << endl;
    }
}