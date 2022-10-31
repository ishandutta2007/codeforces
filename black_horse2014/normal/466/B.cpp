#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

int64 ra, rb, r;

main() {
    
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int64 n, a, b, na, nb, ra, rb, S, A, B;
    cin >> n >> a >> b;
    
    S = 6 * n;
    if (S <= a * b) {
        cout << a * b << endl;
        cout << a << " " << b << endl;
        return 0;
    }
    
    r = 4000000000000000000LL;
    for (A = 1; A <= S; A++) {
        B = S / A;
        if (S % A) B++;
        if (B < A) break;
        na = max(a, A), nb = max(b, B);
        if (na * nb < r) r = na * nb, ra = na, rb = nb;
        na = max(a, B), nb = max(b, A);
        if (na * nb < r) r = na * nb, ra = na, rb = nb;
    }
    cout << r << endl;
    cout << ra << " " << rb << endl;
}