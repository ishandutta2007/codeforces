#include <iostream>
#include <algorithm>
using namespace std;

inline int cm2(const int& x) {
    return x/2+x%2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T --> 0) {
        int s, i, e; cin >> s >> i >> e;
        cout << max(0, s+e-max(s,cm2(s+e+i+1))+1) << endl;
    }
}