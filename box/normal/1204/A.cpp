#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    bool hasOne = false, first = true; int totdig = 0;
    for(char ch:s) {
        if(first) {
            first = false;
            continue;
        }
        if(ch == '1') hasOne = true;
        totdig++;
    }
    cout << totdig/2 + (int)(hasOne || (bool)(totdig % 2)) << endl;
}