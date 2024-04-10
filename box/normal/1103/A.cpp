#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int vert = 0, hori = 0;
    string s; cin >> s;
    for(char c:s) {
        if(c == '0') cout << 1 << ' ' << (vert++)%4+1 << endl;
        else cout << 4 << ' ' << 2*((hori++)%2)+1 << endl;
    }
}