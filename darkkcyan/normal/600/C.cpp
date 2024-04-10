#include <bits/stdc++.h>

using namespace std;

#define ffff(i, a, b, c) for (i a; i b; i c)
#define fff(i, a, b) ffff (i, = a, != b, ++)
#define ff(i, n) fff(i, 0, n)
#define all(v) v.begin(), v.end()

int main (void) {
    ios_base::sync_with_stdio(0);
    int i, f, g;  // count variable

    int charCount['z' + 10] = {0};
    char ch;
    int n = 0;
    while (cin >> ch) {
        charCount[ch] ++;
        ++n;
    }

    f = 'z';
    g = 'a';

    while (true) {
        while (g <= 'z' and charCount[g] % 2 == 0) ++g;
        while (f >= 'a' and charCount[f] % 2 == 0) --f;
        if (g >= f) break;
        ++charCount[g];
        --charCount[f];
    }

    fff (i, 'a', 'z' + 1) {
        ff (g, charCount[i] / 2) cout << (char) i;
    }

    if (n % 2 == 1) cout << (char) f;

    ffff (i, = 'z', >= 'a', --) {
        ff (g, charCount[i] / 2) cout << (char) i;
    }

    return 0;
}