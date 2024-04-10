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

const int max_n = 2e6 + 100;

int is_prime[max_n];

int main() {
    ios_base::sync_with_stdio(false); 
    int n;
    cin >> n;
    for (int i = 2; i < max_n; ++i)
        is_prime[i] = 1;
    for (int i = 2; i * i < max_n; ++i)
        if (is_prime[i])
            for (int j = i * i; j < max_n; j += i)
                is_prime[j] = 0;
    for (int i = 2; i < max_n; ++i)
        if (is_prime[i]) {
            int c = i, r = 0;
            while (c > 0) {
                r = r * 10 + c % 10;
                c /= 10;
            }
            if (r != i && is_prime[r]) {
                --n;
                if (!n) {
                    cout << i << endl;
                    break;
                }
            }
        }

    return 0;
}