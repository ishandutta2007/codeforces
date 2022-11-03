#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int mask = (1 << 30) - 1;

int a, b, c;
int r;

int d(int x) {
    int res = 0;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0) {
            ++res;
            if (i * i != x)
                ++res;
        }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> a >> b >> c;
    r = 0;
    if (b < a) swap(a, b);
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    for (int i = 1; i <= a; ++i) {
        r = (r + d(i * i * i)) & mask;
        for (int k = i + 1; k <= a; ++k)
            r = (r + 3 * d(i * i * k)) & mask;
        for (int k = a + 1; k <= b; ++k)
            r = (r + 2 * d(i * i * k)) & mask;
        for (int k = b + 1; k <= c; ++k)
            r = (r + d(i * i * k)) & mask;
        for (int j = i + 1; j <= a; ++j)
            r = (r + 3 * d(i * j * j)) & mask;
        for (int j = a + 1; j <= b; ++j) 
            r = (r + d(i * j * j)) & mask;
        for (int j = i + 1; j <= a; ++j) {
            for (int k = j + 1; k <= a; ++k)
                r = (r + 6 * d(i * j * k)) & mask;
            for (int k = a + 1; k <= b; ++k)
                r = (r + 4 * d(i * j * k)) & mask;
            for (int k = b + 1; k <= c; ++k)
                r = (r + 2 * d(i * j * k)) & mask;
        }
        for (int j = a + 1; j <= b; ++j) {
            for (int k = j + 1; k <= b; ++k)
                r = (r + 2 * d(i * j * k)) & mask;
            for (int k = b + 1; k <= c; ++k)
                r = (r + d(i * j * k)) & mask;
        }
    }
    cout << r << endl;
    return 0;
}