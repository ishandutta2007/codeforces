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

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int modulo = 1e9 + 7;

const int max_n = 2e3 + 100;

int d[max_n][max_n];
int a[max_n];
int n;
int m;
int k;
int us[max_n];

int main() {
    ios_base::sync_with_stdio(false); 
    d[0][0] = 1;
    for (int i = 1; i < max_n; ++i)
        d[0][i] = 0;
    for (int i = 1; i < max_n; ++i)
        d[i][0] = (1LL * i * d[i - 1][0]) % modulo;
    for (int i = 1; i < max_n; ++i)
        for (int j = 1; j < max_n; ++j) {
            d[i][j] = 0;
            if (j > 1) 
                d[i][j] = (1LL * (j - 1) * d[i - 1][j - 2]) % modulo;
            d[i][j] = (1LL * (i - j) * d[i - 1][j - 1] + d[i][j]) % modulo;
        }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != -1) 
            ++us[a[i]];
    }
    m = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == -1 && !us[i + 1])
            ++m;
    k = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == -1)
            ++k;
    cout << d[k][m] << endl;
    return 0;
}