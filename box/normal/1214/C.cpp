#include <iostream>
#include <string>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int _; cin >> _;
    if(_ == 1) {
        cout << "No" << endl;
        return 0;
    }
    string s; cin >> s;
    int t = 0;
    for(char c:s) {
        if(c == '(') t++;
        if(c == ')') t--;
    }
    if(t != 0) {
        cout << "No" << endl;
        return 0;
    }
    for(int i=0; i<_; i++) {
        if(s[i] == ')') {
            s[i] = ' ';
            s += ')';
            break;
        }
    }
    t = 0;
    for(char c:s) {
        if(c == ' ') continue;
        if(c == '(') t++;
        if(c == ')') t--;
        if(t == -1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}