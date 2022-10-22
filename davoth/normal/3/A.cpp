#include <bits/stdc++.h>
using namespace std;
int main() {
    string s,t;
    cin >> s >> t;
    int x=(t[0]-s[0]);
    int y=(t[1]-s[1]);
    vector<string> a;
    while(x>0&&y>0) {
        x--;
        y--;
        a.push_back("RU");
    }
    while(x>0&&y<0) {
        x--;
        y++;
        a.push_back("RD");
    }
    while(x<0&&y>0) {
        x++;
        y--;
        a.push_back("LU");
    }
    while(x<0&&y<0) {
        x++;
        y++;
        a.push_back("LD");
    }
    while(x>0) {
        x--;
        a.push_back("R");
    }
    while(x<0) {
        x++;
        a.push_back("L");
    }
    while(y>0) {
        y--;
        a.push_back("U");
    }
    while(y<0) {
        y++;
        a.push_back("D");
    }
    cout << a.size() << '\n';
    for(int i=0; i<a.size(); i++){
        cout << a[i] << '\n';
    }
    return 0;
}