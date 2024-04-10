#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int a, b, N; cin >> a >> b >> N;
        N %= 3;
        if(N == 0) cout << a << endl;
        if(N == 1) cout << b << endl;
        if(N == 2) cout << (a^b) << endl;
    }
}