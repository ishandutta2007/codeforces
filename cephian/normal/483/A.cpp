#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

int gcd(ll a, ll b){
    return (b == 0)?a:gcd(b, a%b);
}

int main() {
    
    ll l, r;
    cin >> l >> r;
    
    for(ll a = l; a <= r; ++a) {
        for(ll b = a+1; b <=r; ++b) {
            if(gcd(a, b) != 1)
                continue;
            for(ll c = b+1; c <= r; ++c) {
                if(gcd(b, c) == 1 && gcd(a, c) != 1) {
                    cout << a << " " << b << " " << c << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}