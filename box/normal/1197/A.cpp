#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int ans = n-2;
        int a=0, b=0;
        while(n--) {
            int i; cin >> i;
            if(i >= a) { b = a; a = i; }
            else if(i >= b) { b = i; }
        }
        cout << min(min(a, b) - 1, ans) << endl;
    }
}