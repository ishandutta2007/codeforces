#include <bits/stdc++.h>
using namespace std;

inline int cbit(long long x) {
    int c = 0;
    while(x) {
        c++;
        x &= x-1;
    }
    return c;
}

int main() {
    long long n; int p; cin >> n >> p;
    for(int i=0; i<=10000; i++) {
        if(n-p*i < 0) continue;
        if(cbit(n-p*i) <= i && i <= n-p*i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}