#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int z = 0, o = 0;
    for(int i=0; i<n; i++) {
        char c; cin >> c;
        if(c == '0') z++;
        else o++;
    }
    cout << max(o,z)-min(o,z) << endl;
}