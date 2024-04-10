#include <iostream>
#include <string>
using namespace std;

int cmap[300];


char alt(char c) {
    if(c >= 'a') return c - 'a' + 'A';
    else return c - 'A' + 'a';
}

int main() {
    string targ; cin >> targ;
    string mat; cin >> mat;
    for(char c:mat) {
        cmap[c]++;
    }
    int y = 0, w = 0;
    for(char& c:targ) {
        if(cmap[c]) { y++; cmap[c]--; c = '*'; }
    }
    for(char c:targ) {
        if(c == '*') continue;
        if(cmap[alt(c)]) { w++; cmap[alt(c)]--; }
    }
    cout << y << ' ' << w << endl;
}