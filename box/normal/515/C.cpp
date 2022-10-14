#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    string a;
    for(char c:s) {
        if(c == '2') a += '2';
        if(c == '3') a += '3';
        if(c == '4') a += "322";
        if(c == '5') a += '5';
        if(c == '6') a += "53";
        if(c == '7') a += '7';
        if(c == '8') a += "7222";
        if(c == '9') a += "7332";
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    cout << a << endl;
}