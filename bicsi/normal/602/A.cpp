#include <bits/stdc++.h>

using namespace std;

void Read(uint64_t &x) {
    x = 0;
    int b, t, n;
    cin>>n>>b;
    for(int i=1; i<=n; i++) {
        cin>>t;
        x = x * b + t;
    }
}

int main() {
    uint64_t a, b;
    Read(a);
    Read(b);
    if(a < b) cout << "<";
    if(a > b) cout << ">";
    if(a == b) cout << "=";
}