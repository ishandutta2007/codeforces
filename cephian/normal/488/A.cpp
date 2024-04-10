#include <iostream>

using namespace std;

bool ok(int a) {
    if(a < 0) return ok(-a);
    while(a) {
        if(a%10 == 8) return true;
        a /= 10;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int a;
    cin >> a;
    for(int i = 1; ; ++i) {
        if(ok(a+i)) {
            cout << i << "\n";
            return 0;
        }
    }
}