#include <bits/stdc++.h>

using namespace std;

#define ffff(i, a, b, c) for (i a; i b; i c)
#define fff(i, a, b) ffff (i, = a, != b, ++)
#define ff(i, n) fff(i, 0, n)
#define all(v) v.begin(), v.end()

int main (void) {
    ios_base::sync_with_stdio(0);
    int i, j;

    long long int l, r, k;
    cin >> l >> r >> k;

    long long int num = 1;
    int count = 0;
    while (num <= r) {
        if (num >= l) {
            cout << num << ' ';
            ++count;            
        }
        if (r / k < num) break;
        num *= k;
    }

    if (count == 0) {
        cout << -1;
    }

    return 0;
}