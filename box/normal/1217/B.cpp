#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, A; cin >> n >> A;
        int B = -1, C = -1;
        while(n--) {
            int cut, grow; cin >> cut >> grow;
            if(C < cut) C = cut;
            if(B < (cut-grow)) B = cut - grow;
        }
        A -= C;
        if(A <= 0) {
            cout << 1 << endl;
            continue;
        }
        if(B == 0 || B == -1) {
            cout << -1 << endl;
            continue;
        }
        cout << (A/B + (int)((bool)(A%B))) + 1 << endl;
    }
}