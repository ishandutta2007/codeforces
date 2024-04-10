#include <bits/stdc++.h>
using namespace std;
int main() {
    long long w,h;
    cin >> w >> h;
    w+=h;
    long long r=1;
    for(int i=0; i<w; i++){
        r*=2;
        r%=998244353;
    }
    cout << r;
    return 0;
}