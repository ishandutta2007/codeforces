#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main() {
    int n;
    cin >> n;
    int r=0;
    r+=n/100;
    n%=100;
    r+=n/20;
    n%=20;
    r+=n/10;
    n%=10;
    r+=n/5;
    r+=n%5;
    cout << r;
    return 0;
}