#include <iostream>
using namespace std;

#define MOD 1000000007
long long aray[100005];

int main() {
    aray[1] = 1; aray[2] = 2;
    for(int i=3; i<=100004; i++) aray[i] = (aray[i-1] + aray[i-2]) % MOD;
    int n, m; cin >> n >> m;
    cout << (2*aray[n] + 2*aray[m] - 2) % MOD << endl;
}