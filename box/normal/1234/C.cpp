#include <bits/stdc++.h>
using namespace std;


bool move(string& s1, string& s2, int i, int j, int dir, int n){
    if (j == n){
        if (dir == 1 and i == 1){ return true; }
        return false;
    }
    char v;
    if (i == 0){ v = s1[j]; }
    else { v = s2[j]; }
    
    if (v - '0' < 3){
        if (dir == 1){
            return move(s1, s2, i, j+1, 1, n);
        }
    } else {
        if (i == 0){
            if (dir == 1){
                return move(s1, s2, 1, j, 2, n);
            } else if (dir == 3){
                return move(s1, s2, 0, j+1, 1, n);
            }
        } else {
            if (dir == 1){
                return move(s1, s2, 0, j, 3, n);
            } else if (dir ==2){
                return move(s1, s2, 1, j+1, 1, n);
            }
        }
    }
    return false;
}


int main(){
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        bool res = move(s1, s2, 0, 0, 1, n);
        if (res){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}