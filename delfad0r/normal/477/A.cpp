#include <iostream>

using namespace std;

typedef long long ll;

const ll M = ll(1.0e9) + 7;

int main() {
    ll A, B;
    cin >> A >> B;
    cout << (((((A * (A + 1) / 2) % M) * B + A) % M) * ((B * (B - 1) / 2) % M)) % M;
}