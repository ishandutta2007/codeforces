#include <iostream>
#include <string>
using namespace std;

int main() {
    bool a=0,b=0,C=0,d=0,e=0;
    string s; cin >> s;
    for(char c:s) {
        if(c == 'h') a = 1;
        if(c == 'e' && a) b = 1;
        if(c == 'l' && C) d = 1;
        if(c == 'l' && b) C = 1;
        if(c == 'o' && d) e = 1;
    }
    if(e) cout << "YES" << endl;
    else cout << "NO" << endl;
}