#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>

using namespace std;

typedef long long LL;

bool f(LL a, LL b) {
    if (a > b) return f(b, a);
    if (a == 0) return false;

    bool res = f(b % a, a) == false;
    if (res) return res;
    
    LL q = b / a - 1;

    if (a % 2 == 1)
        res |= q % 2 == 1;
    else
    {
        if ((q % (a + 1)) == a)
            res |= true;
        else
            res |= (q % (a + 1)) % 2;
    }

    return res;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        LL a, b;
        cin >> a >> b;
        if ( f(a, b) ) cout << "First" << endl; else
            cout << "Second" << endl;
    }
}

int main() {
    solve();

    return 0;
}