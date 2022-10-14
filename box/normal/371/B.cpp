#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int v1, v2; cin >> v1 >> v2;
    int a1 = 0, b1 = 0, c1 = 0;
    while(v1 % 5 == 0) { c1++; v1 /= 5; }
    while(v1 % 3 == 0) { b1++; v1 /= 3; }
    while(v1 % 2 == 0) { a1++; v1 /= 2; }
    int a2 = 0, b2 = 0, c2 = 0;
    while(v2 % 5 == 0) { c2++; v2 /= 5; }
    while(v2 % 3 == 0) { b2++; v2 /= 3; }
    while(v2 % 2 == 0) { a2++; v2 /= 2; }
    if(v1 != v2) {
        cout << -1 << endl;
        return 0;
    }
    cout << max(a1,a2)-min(a1,a2)+max(b1,b2)-min(b1,b2)+max(c1,c2)-min(c1,c2) << endl;
}