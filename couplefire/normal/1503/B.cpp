#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> pos1;
    vector<pair<int, int>> pos2;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if((i+j)%2 == 0) pos1.push_back({i, j});
            else pos2.push_back({i, j});
        }
    }
    for(int move = 1; move<=n*n; move++){
        int c; cin >> c;
        if(c == 1){
            if(pos2.empty()){
                cout << 3 << " " << pos1.back().first << " " << pos1.back().second << endl;
                pos1.pop_back();
            }
            else{
                cout << 2 << " " << pos2.back().first << " " << pos2.back().second << endl;
                pos2.pop_back();
            }
        }
        else if(c == 2){
            if(pos1.empty()){
                cout << 3 << " " << pos2.back().first << " " << pos2.back().second << endl;
                pos2.pop_back();
            }
            else{
                cout << 1 << " " << pos1.back().first << " " << pos1.back().second << endl;
                pos1.pop_back();
            }
        }
        else{
            if(pos1.empty()){
                cout << 2 << " " << pos2.back().first << " " << pos2.back().second << endl;
                pos2.pop_back();
            }
            else{
                cout << 1 << " " << pos1.back().first << " " << pos1.back().second << endl;
                pos1.pop_back();
            }
        }
    }
}