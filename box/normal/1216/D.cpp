#include <bits/stdc++.h>
using namespace std;

vector<int> sw;

inline int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c; cin >> c;
    for(int i=0; i<c; i++) {
        int v; cin >> v;
        sw.push_back(v);
    }
    sort(sw.begin(), sw.end(), [](const int a, const int b) {
        return a > b;
    });
    int x = sw[0];
    int z = 0;
    for(int i=0; i<c; i++) {
        z = gcd(sw[0]-sw[i], z);
    }
    long long y = 0;
    for(int i=0; i<c; i++) {
        y += ((sw[0] - sw[i])/z);
    }
    cout << y << ' ' << z << endl;
}