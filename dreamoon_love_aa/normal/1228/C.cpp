#include<bits/stdc++.h>
using namespace std;
long long pw(long long x, long long y) {
    if(y == 0) return 1;
    if(y == 1) return x;
    long long v = pw(x, y / 2);
    if(y & 1) {
        return v * v % 1000000007 * x % 1000000007;
    }
    return v * v % 1000000007;
}
long long f(int p, long long n) {
    long long cnt = 0;
    while(n >= p) {
        cnt += n / p;
        n /= p;
    }
    return pw(p, cnt);
}
int main() {
    int x;
    long long n;
    cin >> x >> n;
    long long an = 1;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            while(x%i ==0){
                x/=i;
            }
            an = an * f(i, n) % 1000000007;
        }
    }
    if(x != 1) an = an * f(x, n) % 1000000007;
    cout << an << endl;
    return 0;
}