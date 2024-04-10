#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a; cin >> a;
    string b; cin >> b;

    if(a != "0") {
        char mnz = '9'; int loc = -1;
        for(int i=0; i<a.size(); i++) {
            if(a[i] <= mnz && a[i] != '0') {
                loc = i;
                mnz = a[i];
            }
        }
        a[loc] = '0';
        sort(a.begin(), a.end());
        a[0] = mnz;
    }
    if(a == b) cout << "OK" << endl;
    else cout << "WRONG_ANSWER" << endl;
}