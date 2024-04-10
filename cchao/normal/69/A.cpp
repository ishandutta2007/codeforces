#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int m[3]={};
    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        m[0] += a;
        m[1] += b;
        m[2] += c;
    }
    cout << ((m[0] | m[1] | m[2]) ? "NO" : "YES") << endl;
    return 0;
}