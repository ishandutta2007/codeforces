#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool solve() {
    int n, R, r;
    cin >> n >> R >> r;

    if (r > R) return false;
    if (n == 1) return true;

    if (r > R / 2) return false;
    if (n == 2) return true;

    double alpha = asin(1.0 * r / (R - r));
    //cerr << alpha << endl;

    return acos(-1.0) + 1e-9 >= n*alpha;
}

int main() {

    if ( solve() ) cout << "YES" << endl; else cout << "NO" << endl;

    return 0;
}